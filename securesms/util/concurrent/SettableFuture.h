#pragma once
/*
Port of template SettableFuture from TextSecure-android
*/

// [ ] done
// TFS ID: 253

#include "ListenableFuture.h"

#include "..\..\..\owntemplates\List.h"
//import java.util.concurrent.ExecutionException;
//import java.util.concurrent.Future;
//import java.util.concurrent.TimeUnit;
//import java.util.concurrent.TimeoutException;

template <typename T> class SettableFuture<T> : Future<T>, ListenableFuture<T>
{
private:
  List<Listener<T>>* listeners = new LinkedList<>();

  bool completed;
  bool canceled;
  volatile T result;
  volatile Throwable exception;
public:
  //@Override
  /*synchronized*/ bool Cancel(bool mayInterruptIfRunning)
  {
    if (!completed && !canceled)
    {
      canceled = true;
      return true;
    }
    return false;
  }
  //@Override
  /*synchronized*/ bool IsCancelled()
  {
    return canceled;
  }
  //@Override
  /*synchronized*/ bool IsDone()
  {
    return completed;
  }
  bool Set(T result)
  {
    synchronized (this) {
      if (completed || canceled) return false;

      this.result    = result;
      this.completed = true;
    }

    notifyAllListeners();
    return true;
  }

  public boolean setException(Throwable throwable) {
    synchronized (this) {
      if (completed || canceled) return false;

      this.exception = throwable;
      this.completed = true;
    }

    notifyAllListeners();
    return true;
  }

  @Override
  public synchronized T get() throws InterruptedException, ExecutionException {
    while (!completed) wait();

    if (exception != null) throw new ExecutionException(exception);
    else                   return result;
  }

  @Override
  public synchronized T get(long timeout, TimeUnit unit)
      throws InterruptedException, ExecutionException, TimeoutException
  {
    long startTime = System.currentTimeMillis();

    while (!completed && System.currentTimeMillis() - startTime > unit.toMillis(timeout)) {
      wait(unit.toMillis(timeout));
    }

    if (!completed) throw new TimeoutException();
    else            return get();
  }

  @Override
  public void addListener(Listener<T> listener) {
    synchronized (this) {
      listeners.add(listener);

      if (!completed) return;
    }

    notifyListener(listener);
  }

  private void notifyAllListeners() {
    List<Listener<T>> localListeners;

    synchronized (this) {
      localListeners = new LinkedList<>(listeners);
    }

    for (Listener<T> listener : localListeners) {
      notifyListener(listener);
    }
  }

  private void notifyListener(Listener<T> listener) {
    if (exception != null) listener.onFailure(new ExecutionException(exception));
    else                   listener.onSuccess(result);
  }
};

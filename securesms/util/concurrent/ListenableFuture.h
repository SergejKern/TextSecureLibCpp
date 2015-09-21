#pragma once
/*
Port of class ListenableFuture from TextSecure-android
*/

// [x] done
// TFS ID: 252

#include "..\..\..\javastuff\ExecutionException.h"

template <typename T> class ListenableFuture<T>
{
public:
  void AddListener(Listener<T> listener);

  class Listener<T>
  {
  public:
    virtual void OnSuccess(T result) = 0;
    virtual void OnFailure(ExecutionException e) = 0;
  };
};

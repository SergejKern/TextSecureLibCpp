#pragma once

/*
Port of LinkedBlockingLifoQueue.java from TextSecure-android
*/

// [x] done
// TFS ID: 225

#include "deque\LinkedBlockingDeque.h"

template <typename E> class LinkedBlockingLifoQueue : LinkedBlockingDeque<E>
{
public:
  //@Override
  virtual void Put(E runnable) /*throws InterruptedException*/
  {
    PutFirst(runnable);
  }
  //@Override
  virtual bool Add(E runnable)
  {
    AddFirst(runnable);
    return true;
  }
  //@Override
  virtual bool Offer(E runnable)
  {
    AddFirst(runnable);
    return true;
  }
};

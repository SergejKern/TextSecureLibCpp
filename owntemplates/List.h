#pragma once

// java.util.List

// [ ] done
// TFS ID: none

#include "Iterable.h"

template <typename T> class List
{
public:
  int Size();
  T* Get(int index);
  bool IsEmpty();
  Iterator<T> iterator();
};
template <typename T> class LinkedList : List<T>
{

};

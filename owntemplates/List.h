#pragma once

// java.util.List

// [ ] done
// TFS ID: none

#include "Collection.h"

/*
public interface List<E> extends Collection<E>
*/
template <typename E> class List : public Collection<E>
{
public:
  int Size();
  E* Get(int index);
  bool IsEmpty();
};
template <typename T> class LinkedList : public List<T>
{

};

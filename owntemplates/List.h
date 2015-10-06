#pragma once

// java.util.List
// http://grepcode.com/file/repository.grepcode.com/java/root/jdk/openjdk/8u40-b25/java/util/List.java#List

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
  E Get(int index);
  bool IsEmpty();
  //boolean[More ...] addAll(Collection< ? extends E> c);
  bool AddAll(Collection<E>* c);
  //boolean[More ...] add(E e);
  bool Add(E e);
};

/*
  java.util.LinkedList
  http://grepcode.com/file/repository.grepcode.com/java/root/jdk/openjdk/8u40-b25/java/util/LinkedList.java#LinkedList
*/

/*
  public class  [More ...] LinkedList<E>
  extends AbstractSequentialList<E>
  implements List<E>, Deque<E>, Cloneable, java.io.Serializable
*/
template <typename E> class LinkedList 
  : public List<E>, Cloneable, Serializable
{
public:
  void AddFirst(E e);
};

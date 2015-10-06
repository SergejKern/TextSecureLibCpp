#pragma once

// java.util.Set
// http://grepcode.com/file/repository.grepcode.com/java/root/jdk/openjdk/8u40-b25/java/util/Set.java#Set

// [ ] done
// TFS ID: none

#include "Collection.h"

// public interface Set<E> extends Collection<E> {
template <typename E> class Set : public Collection<E>
{
public:
  bool Remove(E);
  bool IsEmpty();
  bool Add(E);
  //boolean[More ...] contains(Object o);
  bool Contains(E);
  bool Remove(E);
};

/*
  java.util.AbstractSet
  http://grepcode.com/file/repository.grepcode.com/java/root/jdk/openjdk/8u40-b25/java/util/AbstractSet.java#AbstractSet
*/

//public abstract class[More ...] AbstractSet<E> extends AbstractCollection<E> implements Set<E> {
template <typename E> class AbstractSet
  : public AbstractCollection<E>, public Set < E >
{};

/*
  java.util.HashSet
  http://grepcode.com/file/repository.grepcode.com/java/root/jdk/openjdk/8u40-b25/java/util/HashSet.java#HashSet
*/
template <typename E> class HashSet
  : public AbstractSet<E>, public Set<E>, public Cloneable, public Serializable
{
};

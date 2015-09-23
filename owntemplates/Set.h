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
};

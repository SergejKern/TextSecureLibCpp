#pragma once

// java.util.Set

// [ ] done
// TFS ID: none

#include "Iterable.h"

/*
public interface  [More ...] Collection<E> extends Iterable<E>
*/
template <typename E> class Collection : public Iterable<E>
{

};

/*
   java.util.AbstractCollection
   http://grepcode.com/file/repository.grepcode.com/java/root/jdk/openjdk/8u40-b25/java/util/AbstractCollection.java#AbstractCollection
*/

// public abstract class  [More ...] AbstractCollection<E> implements Collection<E> {
template <typename E> class AbstractCollection : public Collection<E>
{

};

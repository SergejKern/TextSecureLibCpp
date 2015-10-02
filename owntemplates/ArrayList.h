#pragma once

/* java.util.ArrayList
   http://grepcode.com/file/repository.grepcode.com/java/root/jdk/openjdk/8u40-b25/java/util/ArrayList.java#ArrayList
*/

// [ ] done
// TFS ID: none

#include "List.h"
#include "..\javastuff\Serializable.h"
#include "..\javastuff\Cloneable.h"
#include "..\javastuff\RandomAccess.h"

/*
public class  [More ...] ArrayList<E> extends AbstractList<E>
implements List<E>, RandomAccess, Cloneable, java.io.Serializable
*/
template <typename E> class ArrayList 
  : public List<E>, 
  public Serializable,
  public Cloneable,
  public RandomAccess
{
private:
  int size;
public:
  int Size() { return this->size; }
  bool IsEmpty() { return this->size == 0; }
  E GetAt(int index) { return 0; }
  void SetAt(int index, E val) { }
};

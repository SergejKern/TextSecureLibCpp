#pragma once

// java.util.Set

// [ ] done
// TFS ID: none

/*
public interface Iterable<T>
*/
template <typename T> class Iterable
{
public:
  Iterator<T> iterator();
  // C++ for range based for
  T* begin();
  T* end();
};

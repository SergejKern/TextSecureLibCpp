#pragma once

/*
Port of LRUCache.java from TextSecure-android
*/

// [x] done
// TFS ID: 227

#include "..\..\owntemplates\LinkedHashMap.h"
#include "..\..\owntemplates\Map.h"

template <typename K, typename V> class LRUCache<K, V> : LinkedHashMap<K, V>
{
private:
  const int maxSize;
  LRUCache(int maxSize) : maxSize(maxSize) {}
protected:
  //@Override
  template <typename K, typename V> bool RemoveEldestEntry(Map<K, V>::Entry<K, V> eldest)
  {
    return Size() > this->maxSize;
  }
};

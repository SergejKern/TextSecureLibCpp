#pragma once

// java.util.LinkedHashMap

// [ ] done
// TFS ID: none

/*
public class LinkedHashMap<K,V>
extends HashMap<K,V>
implements Map<K,V>
*/

#include "HashMap.h"
#include "Map.h"

template <typename K, typename V> class LinkedHashMap : HashMap<K, V>, Map<K, V>
{
public:
  //V Get(K key);
  //bool ContainsKey(K key);
  //V Remove(K key);
  //V Put(K key, V value);
};

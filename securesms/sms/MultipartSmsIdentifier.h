#pragma once

// java.util.Set

// [ ] done
// TFS ID: none

/*
public class HashMap<K,V> extends AbstractMap<K,V> implements Map<K,V>, Cloneable, Serializable
*/
template <typename K, typename V> class HashMap
{
public:
  V Get(K key);
  bool ContainsKey(K key);
  V Remove(K key);
  V Put(K key, V value);
};

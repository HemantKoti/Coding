/*
 * HashMap.h
 *
 *  Created on: Jan 16, 2018
 *      Author: HemantKo
 */

#ifndef ARRAYSANDSTRINGS_CUSTOMHASHMAP_HASHMAP_H_
#define ARRAYSANDSTRINGS_CUSTOMHASHMAP_HASHMAP_H_
#include "../../StandardHeader.h"

template<class K, class V>
class HashMapUtil{
private:
	K key;
	V value;
};

template<class K, class V>
class HashMap {
private:
	HashMapUtil<K,V>* _hashMap;
	static int _defaultCapacity;
	int _size = 0;
public:
	HashMap();
	HashMap(int capacity);
	void Add(K key, V value);
	void Clear();
	bool ContainsKey(K key);
	bool ContainsValue(V value);
	K* GetKeys();
	V* GetValues();
	V GetValue(K key);
	bool Remove(K key);
	int Size();
	V SetValue(K key, V value);
};

#endif /* ARRAYSANDSTRINGS_CUSTOMHASHMAP_HASHMAP_H_ */

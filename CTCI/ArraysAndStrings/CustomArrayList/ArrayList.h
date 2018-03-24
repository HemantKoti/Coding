/*
 * ArrayListCustom.h
 *
 *  Created on: Nov 24, 2017
 *      Author: HemantKo
 */

#ifndef ARRAYSANDSTRINGS_CUSTOMARRAYLIST_ARRAYLIST_H_
#define ARRAYSANDSTRINGS_CUSTOMARRAYLIST_ARRAYLIST_H_
#include "../../StandardHeader.h"

template<class T>
class ArrayList {
private:
	T* _arrayList;
	static int _defaultCapacity;
	int _size = 0;
public:
	ArrayList();
	ArrayList(int capacity);
	int Add(T element);
	bool Contains(T element);
	T Get(int index);
	int IndexOf(T element);
	void Print();
	void Remove(T element);
	void RemoveAt(int index);
	int Size();
	// To-Do: Revisit when sorting is covered
	T* Sort(T* _arrayList);
};

#endif /* ARRAYSANDSTRINGS_CUSTOMARRAYLIST_ARRAYLIST_H_ */

/*
 * ArrayListCustom.h
 *
 *  Created on: Nov 24, 2017
 *      Author: HemantKo
 */

#ifndef ARRAYSANDSTRINGS_ARRAYLIST_ARRAYLIST_H_
#define ARRAYSANDSTRINGS_ARRAYLIST_ARRAYLIST_H_
#include "../../StandardHeader.h"

template<class T>
class ArrayList {
private:
	T* _arrayList;
	int _defaultCapacity = 4;
	int count = 0;
public:
	ArrayList();
	ArrayList(int capacity);
	void add(T element);
	bool contains(T element);
	T get(int index);
	void print();
	void remove(T element);
	void removeAt(int index);
	int search();
	int size();
};

#endif /* ARRAYSANDSTRINGS_ARRAYLIST_ARRAYLIST_H_ */

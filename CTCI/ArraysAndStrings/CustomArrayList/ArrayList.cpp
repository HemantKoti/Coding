/*
 * ArrayListCustom.cpp
 *
 *  Created on: Nov 24, 2017
 *      Author: HemantKo
 */

#include "../CustomArrayList/ArrayList.h"

template class ArrayList<int> ;
template class ArrayList<float> ;
template class ArrayList<double> ;
template class ArrayList<string> ;

/*
 * Creates a new instance of the ArrayList class that is empty and has the default initial capacity of 4
 */
template<class T>
ArrayList<T>::ArrayList() {
	_arrayList = new T[_defaultCapacity];
}

/*
 * Creates a new instance of the ArrayList class that has a custom capacity
 */
template<class T>
ArrayList<T>::ArrayList(int capacity) {
	_arrayList = new T[capacity];
	count = capacity;
}

/*
 * Adds an element to the end of the ArrayList
 */
template<class T>
void ArrayList<T>::add(T element) {
	if (count < _defaultCapacity) {
		_arrayList[count++] = element;
	} else {
		_defaultCapacity = count * 2;
		T* _arrayListTemp = new T[_defaultCapacity];
		memcpy(_arrayListTemp, _arrayList, count * sizeof(T));
		_arrayListTemp[count++] = element;
		delete[] _arrayList;
		_arrayList = _arrayListTemp;
	}
}

/*
 * Determines whether an element is in the ArrayList
 */
template<class T>
bool ArrayList<T>::contains(T element) {
	for (int i = 0; i < count; i++) {
		if (_arrayList[i] == element) {
			return true;
		}
	}
	return false;
}

/*
 * Returns an Array List element based on the index passed
 */
template<class T>
T ArrayList<T>::get(int index) {
	assert(count > index && "Invalid index");
	return _arrayList[index];
}

/*
 * Searches for the specified element and returns the zero-based index of the first occurrence within the range of elements in the ArrayList that starts at the specified index and contains the specified number of elements
 */
template<class T>
int ArrayList<T>::indexOf(T element) {
	assert(contains(element) && "Element not found to remove");
	for (int i = 0; i < count; i++) {
		if (_arrayList[i] == element) {
			return i;
		}
	}
	return -1;
}

/*
 * Removes the first occurrence of a specific element from the ArrayList
 */
template<class T>
void ArrayList<T>::remove(T element) {
	assert(contains(element) && "Element not found to remove");
	int index = indexOf(element);
	for (int i = index; i < count - 1; i++) {
		_arrayList[i] = _arrayList[i + 1];
	}
	_arrayList[--count] = (T) 0;
}

/*
 * Removes the element at the specified index of the ArrayList
 */
template<class T>
void ArrayList<T>::removeAt(int index) {
	assert(index >= 0 && count > index && "Invalid index");
	for (int i = index; i < count - 1; i++) {
		_arrayList[i] = _arrayList[i + 1];
	}
	_arrayList[--count] = (T) 0;
}

/*
 * Prints all the elements in the Array List
 */
template<class T>
void ArrayList<T>::print() {
	assert(count > 0 && "Empty Array");
	for (int i = 0; i < count + 10; i++) {
		cout << _arrayList[i] << endl;
	}
}

/*
 * Returns the size of the Array List
 */
template<class T>
int ArrayList<T>::size() {
	return count;
}


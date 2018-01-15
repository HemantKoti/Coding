/*
 * ArrayListCustom.cpp
 *
 *  Created on: Nov 24, 2017
 *      Author: HemantKo
 */

#include "ArrayList.h"

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
 * Creates a new instance of the ArrayList class with a custom capacity
 */
template<class T>
ArrayList<T>::ArrayList(int capacity) {
	assert(capacity < 1 && capacity > INT_MAX - 1 && "Invalid Capacity");

	_arrayList = new T[capacity];

	// Set the default capacity with newly assigned size
	_defaultCapacity = capacity;
}

/*
 * Adds an element to the end of the ArrayList
 */
template<class T>
int ArrayList<T>::Add(T element) {

	/* Check if the current count value is less than the allocated size of the ArrayList
	* If not increase the size of the ArrayList by 2 and resize the ArrayList */
	if (_count < _defaultCapacity) {
		_arrayList[_count++] = element;
	} else {
		_defaultCapacity = _defaultCapacity * 2;
		T* _arrayListTemp = new T[_defaultCapacity];

		memcpy(_arrayListTemp, _arrayList, _count * sizeof(T));
		_arrayListTemp[_count++] = element;

		delete[] _arrayList;
		_arrayList = _arrayListTemp;
		delete[] _arrayListTemp;
	}

	return _count - 1;
}

/*
 * Determines whether an element is in the ArrayList
 */
template<class T>
bool ArrayList<T>::Contains(T element) {
	for (int i = 0; i < _count; i++) {
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
T ArrayList<T>::Get(int index) {
	assert(_count > index && "Invalid index");
	return _arrayList[index];
}

/*
 * Searches for the specified element and returns the zero-based index of the first occurrence within the range of elements in the ArrayList that starts at the specified index and contains the specified number of elements
 */
template<class T>
int ArrayList<T>::IndexOf(T element) {
	assert(Contains(element) && "Element not found to remove");
	for (int i = 0; i < _count; i++) {
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
void ArrayList<T>::Remove(T element) {
	assert(Contains(element) && "Element not found to remove");
	int index = IndexOf(element);
	for (int i = index; i < _count - 1; i++) {
		_arrayList[i] = _arrayList[i + 1];
	}
	_arrayList[--_count] = (T) 0;
}

/*
 * Removes the element at the specified index of the ArrayList
 */
template<class T>
void ArrayList<T>::RemoveAt(int index) {
	assert(index >= 0 && _count > index && "Invalid index");
	for (int i = index; i < _count - 1; i++) {
		_arrayList[i] = _arrayList[i + 1];
	}
	_arrayList[--_count] = (T) 0;
}

/*
 * Prints all the elements in the Array List
 */
template<class T>
void ArrayList<T>::Print() {
	assert(_count > 0 && "Empty Array");
	for (int i = 0; i < _count + 10; i++) {
		cout << _arrayList[i] << endl;
	}
}

/*
 * Returns the size of the Array List
 */
template<class T>
int ArrayList<T>::Size() {
	return _count;
}


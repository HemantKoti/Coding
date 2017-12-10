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

template<class T>
ArrayList<T>::ArrayList() {
	_arrayList = new T[_defaultCapacity];
}

template<class T>
ArrayList<T>::ArrayList(int capacity) {
	_arrayList = new T[capacity];
	count = capacity;
}

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

template<class T>
bool ArrayList<T>::contains(T element) {
	for (int i = 0; i < count; i++) {
		if (_arrayList[i] == element) {
			return true;
		}
	}
	return false;
}

template<class T>
T ArrayList<T>::get(int index) {
	assert(count > index && "Invalid index");
	return _arrayList[index];
}

//template<class T>
//void ArrayList<T>::remove(T element) {
//	for (int i = index; i < count - 1; i++) {
//		_arrayList[i] = _arrayList[i + 1];
//	}
//	_arrayList[count--] = (T) 0;
//}

template<class T>
void ArrayList<T>::removeAt(int index) {
	assert(index >= 0 && count > index && "Invalid index");
	for (int i = index; i < count - 1; i++) {
		_arrayList[i] = _arrayList[i + 1];
	}
	_arrayList[count--] = (T) 0;
}

template<class T>
void ArrayList<T>::print() {
	assert(count > 0 && "Empty Array");
	for (int i = 0; i < count; i++) {
		cout << _arrayList[i] << endl;
	}
}

//template<class T>
//int ArrayList<T>::search() {
//	for (int i = 0; i < count; i++) {
//		if (_arrayList[i] == element) {
//			return i;
//		}
//	}
//	return -1;
//}

template<class T>
int ArrayList<T>::size() {
	return count;
}


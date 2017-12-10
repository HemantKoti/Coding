/*
 * main.cpp
 *
 *  Created on: Nov 24, 2017
 *      Author: HemantKo
 */

#include "ArraysAndStrings/ArrayList/ArrayList.h"

void ArrayListTest() {
	ArrayList<int> alInt;
	cout << "Integer Array List" << endl;
	for (int i = 0; i < 10; i++) {
		alInt.add(i + 1);
	}
	alInt.removeAt(3);
	cout << "Size = " << alInt.size() << endl;
	alInt.print();
}

void StringBuilderTest() {

}

int main() {
	ArrayListTest();
	StringBuilderTest();
	return EXIT_SUCCESS;
}


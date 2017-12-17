/*
 * main.cpp
 *
 *  Created on: Nov 24, 2017
 *      Author: HemantKo
 */

#include "ArraysAndStrings/CustomArrayList/ArrayList.h"

/*
 * Unit tests for Custom Array List implementation
 */
void ArrayListTest() {
	ArrayList<int> alInt;
	cout << "Integer Array List" << endl;
	for (int i = 0; i < 10; i++) {
		alInt.add(i + 1);
	}
	alInt.remove(5);
	alInt.removeAt(6);
	cout << "Size = " << alInt.size() << endl;
	alInt.print();
}

/*
 * Unit tests for Custom String Builder implementation
 */
void StringBuilderTest() {

}

int main() {
	ofstream errorLog("ErrorLogging/MyTrace.txt",
			ios_base::app | ios_base::out);
	try {
		ArrayListTest();
		StringBuilderTest();
	} catch (exception & ex) {
		errorLog << ex.what() << endl;
	}
	return EXIT_SUCCESS;
}


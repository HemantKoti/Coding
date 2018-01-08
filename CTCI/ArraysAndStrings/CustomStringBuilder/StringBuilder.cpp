/*
 * StringBuilder.cpp
 *
 *  Created on: Dec 11, 2017
 *      Author: HemantKo
 */

#include "../CustomStringBuilder/StringBuilder.h"

void ReSizeArray(){

}
/*
 * Creates a new instance of the StringBuilder class that is empty and has the default initial capacity of 4
 */
StringBuilder::StringBuilder() {
	_stringBuilder = new char[_defaultCapacity];
}

/*
 * Creates a new instance of the StringBuilder class that has a custom capacity
 */
StringBuilder::StringBuilder(int capacity) {
	_stringBuilder = new char[capacity];
	_defaultCapacity = capacity;
}

StringBuilder StringBuilder::Append(bool flag){
	char* flagString;
	if(flag){
		flagString = new char{"false"};
	}else{
		flagString = new char{"true"};
	}

	// To - Do
	return _stringBuilder;
}

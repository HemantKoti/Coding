/*
 * StringBuilder.cpp
 *
 *  Created on: Dec 11, 2017
 *      Author: HemantKo
 */

#include "../CustomStringBuilder/StringBuilder.h"

char* ResizeArray(char *sourceArray, char const* destinationArray){
	int newCapacity = strlen(sourceArray) * 2 + strlen(destinationArray);
	char* sourceArrayTemp = new char[newCapacity];

	memcpy(sourceArrayTemp, sourceArray, strlen(sourceArray) * sizeof(char));
	delete(sourceArray);
	strcat(sourceArrayTemp, destinationArray);

	return sourceArrayTemp;
}

char* AppendUtil(char* sourceString, char const* destinationString) {
	if (strlen(sourceString) < strlen(destinationString)) {
		return ResizeArray(sourceString, destinationString);
	}
	return strcat(sourceString, destinationString);
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

StringBuilder* StringBuilder::Append(bool flag) {
	// explore
	char const* flagString;

	if (flag) {
		flagString = "true";
	} else {
		flagString =  "false";
	}

	_stringBuilder = AppendUtil(_stringBuilder, flagString);

	// explore
	return this;
}

char* StringBuilder::ToString(){
	return this->_stringBuilder;
}

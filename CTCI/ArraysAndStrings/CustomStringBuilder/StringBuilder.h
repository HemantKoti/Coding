/*
 * StringBuilder.h
 *
 *  Created on: Dec 11, 2017
 *      Author: HemantKo
 */

#ifndef ARRAYSANDSTRINGS_CUSTOMSTRINGBUILDER_STRINGBUILDER_H_
#define ARRAYSANDSTRINGS_CUSTOMSTRINGBUILDER_STRINGBUILDER_H_
#include "../../StandardHeader.h"

class StringBuilder {
private:
	char* _stringBuilder;
	int _defaultCapacity = 4;
	int _count = 0;
public:
	StringBuilder();
	StringBuilder(int capacity);
	StringBuilder Append(bool flag);
	StringBuilder Append(char ch);
	StringBuilder Append(char ch, int repeatCount);
	StringBuilder Append(char charArray[]);
	StringBuilder Append(int value);
	StringBuilder Append(double value);
	StringBuilder Append(string str);
	StringBuilder Clear();
	StringBuilder Insert(int index, bool flag);
	StringBuilder Insert(int index, char ch);
	StringBuilder Insert(int index, char charArray[]);
	StringBuilder Insert(int index, int value);
	StringBuilder Insert(int index, double value);
	StringBuilder Insert(int index, string str);
	StringBuilder Remove(int startIndex, int length);
	StringBuilder RemoveAt(int index);
	string ToString();
	int Length();
};

#endif /* ARRAYSANDSTRINGS_CUSTOMSTRINGBUILDER_STRINGBUILDER_H_ */

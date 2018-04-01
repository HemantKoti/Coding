/*
 * BinaryRepresentation.cpp
 *
 *  Created on: Apr 1, 2018
 *      Author: HemantKo
 */

#include "../InterviewBit.h"

string findDigitsInBinary(int A) {
	string str = "";
	int remainder = 0;
	if (A == 0 || A == 1) {
		str += (A + '0');
		return str;
	}
	while (A > 0) {
		remainder = A % 2;
		str += (remainder + '0');
		A /= 2;
	}
	reverse(str.begin(), str.end());
	return str;
}

/*
 * ReverseInteger.cpp
 *
 *  Created on: Apr 2, 2018
 *      Author: HemantKo
 */

#include "../InterviewBit.h"

int reverse(int A) {
	bool isNegative = A < 0 ? true : false;
	long long temp = abs(A), reverse = 0;
	int numberOfDigits = 0, rem = 0;
	while (A) {
		A /= 10;
		numberOfDigits++;
	}
	A = temp;
	while (A) {
		rem = A % 10;
		A /= 10;
		reverse += rem * pow(10, --numberOfDigits);
	}
	reverse = isNegative ? -reverse : reverse;
	return reverse < INT_MIN || reverse > INT_MAX ? 0 : reverse;
}


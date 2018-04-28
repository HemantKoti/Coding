/*
 * DecimalToBinary.cpp
 *
 *  Created on: Apr 26, 2018
 *      Author: HemantKo
 */

#include "../InterviewBit.h"

string decimalToBinary(int A) {
	string binary = "";
	while (A) {
		int rem = A % 2;
		A /= 2;
		binary += rem;
	}
	reverse(binary.begin(), binary.end());
	return binary;
}



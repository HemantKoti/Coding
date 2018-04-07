/*
 * ExcelColumnTitle.cpp
 *
 *  Created on: Apr 7, 2018
 *      Author: HemantKo
 */

#include "../InterviewBit.h"

string convertToTitle(int A) {
	string str = "";
	int rem = 0;
	while (A) {
		rem = A % 26;
		str += (rem == 0 ? 26 : A % 26) + 'A' - 1;
		A = (rem == 0 ? A / 26 - 1 : A / 26);
	}
	reverse(str.begin(), str.end());
	return str;
}

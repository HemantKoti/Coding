/*
 * ExcelColumnNumber.cpp
 *
 *  Created on: Apr 7, 2018
 *      Author: HemantKo
 */

#include "../InterviewBit.h"

int titleToNumber(string A) {
	int result = 0;
	for (int i = 0, j = A.size() - 1; i < A.size(), j >= 0; i++, j--) {
		result += (A[j] - 'A' + 1) * pow(26, i);
	}
	return result;
}


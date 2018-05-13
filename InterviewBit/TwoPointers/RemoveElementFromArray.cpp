/*
 * RemoveElementFromArray.cpp
 *
 *  Created on: May 14, 2018
 *      Author: HemantKo
 */

#include "../InterviewBit.h"

int removeElement(vector<int> &A, int B) {
	int i = 0;
	for (; i < A.size(); i++) {
		if (A[i] == B)
			break;
	}

	for (int j = i + 1; j < A.size(); j++) {
		if (A[j] != B) {
			A[i] = A[j];
			i++;
		}
	}
	return i;
}


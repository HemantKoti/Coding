/*
 * FirstMissingInteger.cpp
 *
 *  Created on: Apr 1, 2018
 *      Author: HemantKo
 */

#include "../InterviewBit.h"

int firstMissingPositive(vector<int> &A) {
	for (int i = 0; i < A.size(); i++) {
		if (A[i] >= 1 && A[i] <= A.size()) {
			int position = A[i] - 1;
			if (A[position] != A[i]) {
				swap(A[position], A[i]);
				i--;
			}
		}
	}

	for (int i = 0; i < A.size(); i++) {
		if (A[i] != i + 1) {
			return i + 1;
		}
	}

	return A.size() + 1;
}


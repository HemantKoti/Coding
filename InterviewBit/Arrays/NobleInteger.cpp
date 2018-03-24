/*
 * NobleInteger.cpp
 *
 *  Created on: Feb 26, 2018
 *      Author: HemantKo
 */

#include "../InterviewBit.h"

int solve(vector<int> &A) {
	sort(A.begin(), A.end());

	// If the largest element is 0, then 0 elements are greater than 0 which is true
	if (A[A.size() - 1] == 0) {
		return 1;
	}

	for (int i = A.size() - 1, j = 0; i >= 0; i--, j++) {
		// To check if largest element does not exceed itself
		// Sample Input:
		// 9 9 9 9 9 9 9 9 9 9 8 8 8 8 8 7 7 7 7 7 7 7 7 7 6 6 6 6 6 6 6 6 6 6 6 6 5 5 5 5 5 5 5
		// 5 5 5 4 4 4 4 4 4 4 3 3 3 3 3 3 3 3 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1 1 1 0 0 0 0 0 0 0
		// 0 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -2 -2 -2 -2 -2 -2 -2 -2 -2 -2 -3 -3 -3 -3 -3 -3 -3
		// -3 -3 -3 -3 -3 -4 -4 -4 -4 -4 -4 -4 -4 -4 -4 -4 -4 -5 -5 -5 -5 -5 -5 -5 -5 -6 -6 -6 -6
		// -6 -6 -6 -6 -6 -6 -6 -7 -7 -7 -7 -7 -7 -7 -7 -8 -8 -8 -8 -8 -8 -8 -8 -8 -9 -9 -9 -9 -9
		// -9 -9 -9 -9 -10 -10 -10 -10 -10 -10 -10
		if (i + 1 < A.size() && j == A[i] && j != A[i + 1]) {
			return 1;
		}
	}
	return -1;
}


/*
 * RearrangeArray.cpp
 *
 *  Created on: Apr 14, 2018
 *      Author: HemantKo
 */

#include "../InterviewBit.h"

void arrange(vector<int> &A) {
	int n = A.size();
	for (int i = 0; i < n; i++) {
		A[i] += (A[A[i]] % n) * n;
	}

	for (int i = 0; i < n; i++) {
		A[i] /= n;
	}
}


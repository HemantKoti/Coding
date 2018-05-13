/*
 * IntersectionOfSortedArrays.cpp
 *
 *  Created on: May 14, 2018
 *      Author: HemantKo
 */

#include "../InterviewBit.h"

vector<int> intersect(const vector<int> &A, const vector<int> &B) {
	vector<int> result;

	for (int i = 0, j = 0; i < A.size() && j < B.size();) {
		if (A[i] == B[j]) {
			result.push_back(A[i]);
			i++;
			j++;
		} else if (A[i] > B[j])
			j++;
		else
			i++;
	}

	return result;
}


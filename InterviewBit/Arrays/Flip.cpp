/*
 * Flip.cpp
 *
 *  Created on: Feb 17, 2018
 *      Author: HemantKo
 */

#include "../InterviewBit.h"

vector<int> flip(string A) {
	vector<int> arr, flip_pair;
	for (int i = 0; i < A.size(); i++) {
		arr.push_back(A[i] == '1' ? -1 : 1);
	}
	Kadan result = kadan(arr);
	if (result.max_sum < 0) {
		flip_pair.push_back(result.l);
		flip_pair.push_back(result.r);
	}
	return flip_pair;
}


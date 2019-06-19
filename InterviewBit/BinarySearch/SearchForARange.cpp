/*
 * SearchForARange.cpp
 *
 *  Created on: Apr 20, 2018
 *      Author: HemantKo
 */

#include "../InterviewBit.h"

int searchRangeUtil(const vector<int> &A, int B, bool searchFirst) {
	int start = 0, end = A.size() - 1, resultidx = -1;
	while (start <= end) {
		int mid = start + (end - start) / 2;
		if (B == A[mid]) {
			resultidx = mid;
			if (searchFirst)
				end = mid - 1;
			else
				start = mid + 1;
		} else if (B < A[mid])
			end = mid - 1;
		else
			start = mid + 1;
	}
	return resultidx;
}

vector<int> searchRange(const vector<int> &A, int B) {
	vector<int> result;
	result.push_back(searchRangeUtil(A, B, true));
	result.push_back(searchRangeUtil(A, B, false));
	return result;
}


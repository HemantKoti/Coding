/*
 * RotatedSortedArraySearch.cpp
 *
 *  Created on: Apr 21, 2018
 *      Author: HemantKo
 */

#include "../InterviewBit.h"

int search(const vector<int> &A, int B) {
	int start = 0, end = A.size() - 1;
	while (start <= end) {
		int mid = (start + end) / 2;
		if (A[mid] == B)
			return mid;
		else if (A[mid] <= A[end]) { // check if the right half is sorted
			if (B > A[mid] && B <= A[end])
				start = mid + 1;
			else
				end = mid - 1;
		} else { // check if the left half is sorted
			if (B >= A[start] && B < A[mid])
				end = mid - 1;
			else
				start = mid + 1;
		}
	}
	return -1;
}


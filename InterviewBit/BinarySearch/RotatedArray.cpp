/*
 * RotatedArray.cpp
 *
 *  Created on: Apr 18, 2018
 *      Author: HemantKo
 */

#include "../InterviewBit.h"

int findMin(const vector<int> &A) {
	int n = A.size();
	int start = 0, end = n - 1;
	while (start <= end) {
		int mid = start + (end - start) / 2;
		if (A[start] <= A[end]) // if start and end are already sorted, return the starting index
			return A[start];
		else if (A[mid] <= A[(mid + 1) % n] && A[mid] <= A[(mid + n - 1) % n]) // check if the mid element is less the prev and next element, if yes then return it
			return A[mid];
		else if (A[mid] <= A[end]) // if the array ranging between mid and end is already sorted, then move on to the first half
			end = mid - 1;
		else if (A[mid] >= A[start]) // if the array ranging between mid and end is already sorted, then move on to the second half
			start = mid + 1;
	}
	return A[0];
}


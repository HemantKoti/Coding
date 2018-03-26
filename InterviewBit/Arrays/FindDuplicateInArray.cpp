/*
 * FindDuplicateInArray.cpp
 *
 *  Created on: Feb 28, 2018
 *      Author: HemantKo
 */

#include "../InterviewBit.h"

int findDuplicateInArray(const vector<int> &A) {
	// Explanation: https://stackoverflow.com/a/33336366/6379722
	if (A.size() <= 1) {
		return -1;
	}
	int slow = A[0], fast = A[A[0]];
	while (slow != fast) {
		slow = A[slow];
		fast = A[A[fast]];
	}
	fast = A[0];
	while (slow != fast) {
		slow = A[slow];
		fast = A[fast];
	}
	return slow;
}


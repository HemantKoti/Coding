/*
 * MaximumSumContiguousSubarray.cpp
 *
 *  Created on: Feb 10, 2018
 *      Author: HemantKo
 */

#include "../InterviewBit.h"

int maxSubArray(const vector<int> &A) {
	int maxSum = INT_MIN, sum = 0;
	for (int i = 0; i < A.size(); i++) {
		sum += A[i];
		sum = A[i] >= sum ? A[i] : sum;
		maxSum = max(maxSum, sum);
	}
	return maxSum;
}

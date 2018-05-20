/*
 * PaintersPartitionProblem.cpp
 *
 *  Created on: May 19, 2018
 *      Author: HemantKo
 */

#include "../InterviewBit.h"
#define MODULUS 10000003

int getNumberOfPartitions(vector<int> &C, LL maxLimitPerPainter) {
	LL total = 0, numPartitions = 1;
	for (int i = 0; i < C.size(); i++) {
		total += C[i];
		if (total >= maxLimitPerPainter) {
			total = C[i];
			numPartitions++;
		}
	}

	return numPartitions;
}

int paint(int A, int B, vector<int> &C) {
	if (C.size() == 1)
		return A * B;
	else if (A == 1)
		return accumulate(C.begin(), C.end(), A) * B;

	LL low = *max_element(C.begin(), C.end()), high = accumulate(C.begin(),
			C.end(), high), result = INT_MAX;

	while (low <= high) {
		LL mid = low + (high - low) / 2;
		if (getNumberOfPartitions(C, mid) <= A) {
			result = min(result, mid);
			high = mid - 1;
		} else
			low = mid + 1;
	}

	return (result * B) % MODULUS;
}

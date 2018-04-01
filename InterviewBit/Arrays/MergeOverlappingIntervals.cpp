/*
 * MergeOverlappingIntervals.cpp
 *
 *  Created on: Mar 26, 2018
 *      Author: HemantKo
 */

#include "../InterviewBit.h"

bool myCmp(Interval a, Interval b) {
	return a.start < b.start;
}

vector<Interval> merge(vector<Interval> &A) {
	// sort based on ranges
	sort(A.begin(), A.end(), myCmp);
	int i = 0;
	for (int j = 1; j < A.size(); j++) {
		// If there is an overlap. Copy the end range with maximum value, between i and j.
		if (A[i].end >= A[j].start) {
			A[i].end = max(A[i].end, A[j].end);
		} else { // If no overlap, copy the values to i index.
			i++;
			A[i].start = A[j].start;
			A[i].end = A[j].end;
		}
	}
	// Remove all the extra elements in the list.
	A.erase(A.begin() + i + 1, A.end());
	return A;
}


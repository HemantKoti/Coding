/*
 * MedianOfArray.cpp
 *
 *  Created on: Apr 21, 2018
 *      Author: HemantKo
 */

#include "../InterviewBit.h"

double findMedianSortedArrays(const vector<int> &A, const vector<int> &B) {
	int partitionA, partitionB;
	int start = 0, end = A.size() - 1;
	if (A.size() == 0 && B.size() != 0) {
		if (B.size() & 1) {
			return B[(B.size() - 1) / 2]; // return the mid element.
		} else {
			int mid = (B.size() - 1) / 2;
			return (B[mid] + B[mid + 1]) / 2; // return average of the mid elements.
		}
	} else if (A.size() != 0 && B.size() == 0) {
		if (A.size() & 1) {
			return A[(A.size() - 1) / 2]; // return the mid element.
		} else {
			int mid = (A.size() - 1) / 2;
			return (A[mid] + A[mid + 1]) / 2; // return average of the mid elements.
		}
	} else {
		while (start <= end) {
			partitionA = (start + end) / 2;
			partitionB = (A.size() + B.size() + 1) / 2 - partitionA; // The extra 1 denotes there is an extra element on left side of partition than on the right side, this is when the total number of elements together in A and B array are odd in number.

			// Set the values for maximum element in left side of partition the in A, and minimum element in right side of the partition in A.
			int maxLeftA = partitionA == 0 ? INT_MIN : A[partitionA - 1];
			int minRightA = partitionA == A.size() ? INT_MAX : A[partitionA];

			// Set the values for maximum element in left side of partition the in B, and minimum element in right side of the partition in B.
			int maxLeftB = partitionB == 0 ? INT_MIN : B[partitionB - 1];
			int minRightB = partitionB == B.size() ? INT_MAX : B[partitionB];

			if (maxLeftA <= minRightB && maxLeftB <= minRightA) {
				if ((A.size() + B.size()) & 1)
					return max(maxLeftA, maxLeftB);
				else
					return (max(maxLeftA, maxLeftB) + min(minRightA, minRightB))
							/ 2;
			} else if (maxLeftA > minRightB) { // The partitionA is too much to the right, go left
				end = partitionA - 1;
			} else
				// The partitionA is too much to the left, go right
				start = partitionA + 1;
		}
	}
	return -1;
}

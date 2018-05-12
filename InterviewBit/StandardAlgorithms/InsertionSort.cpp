/*
 * InsertionSort.cpp
 *
 *  Created on: Mar 4, 2018
 *      Author: HemantKo
 */

#include "../InterviewBit.h"

void InsertionSort(vector<int> &A) {
	for (int i = 1; i < A.size() - 1; i++) {
		int hole = i;
		int value = A[i];
		while (hole > 0 && A[hole - 1] > value) {
			A[hole] = A[hole - 1];
			hole--;
		}
		A[hole] = value;
	}
}


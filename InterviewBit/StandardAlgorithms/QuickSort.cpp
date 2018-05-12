/*
 * QuickSort.cpp
 *
 *  Created on: Mar 10, 2018
 *      Author: HemantKo
 */

#include "../InterviewBit.h"

int partition(vector<int> &A, int start, int end) {
	int pivotElement = A[end], pivot = start;
	for (int i = start; i < end; i++) {
		if (A[i] <= pivotElement) {
			swap(A[pivot++], A[i]);
		}
	}
	swap(A[pivot], A[end]);
	return pivot;
}

void QuickSort(vector<int> &A, int start, int end) {
	if (start >= end) {
		return;
	}
	int pivot = partition(A, start, end);
	QuickSort(A, start, pivot - 1);
	QuickSort(A, pivot + 1, end);
}

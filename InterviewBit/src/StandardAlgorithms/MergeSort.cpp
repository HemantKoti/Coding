/*
 * MergeSort.cpp
 *
 *  Created on: Mar 5, 2018
 *      Author: HemantKo
 */

#include "../../include/interviewbit.h"

void Merge(vector<int> &A, vector<int> &left, vector<int> &right)
{
	int i = 0, j = 0, k = 0;

	while (i < left.size() && j < right.size())
	{
		A[k++] = left[i] <= right[j] ? left[i++] : right[j++];
	}

	while (i < left.size())
	{
		A[k++] = left[i++];
	}

	while (j < right.size())
	{
		A[k++] = right[j++];
	}
}

void MergeSort(vector<int> &A)
{
	if (A.size() < 2)
	{
		return;
	}
	int mid = A.size() / 2;
	vector<int> left(A.begin(), A.begin() + mid);
	vector<int> right(A.begin() + mid, A.end());
	MergeSort(left);
	MergeSort(right);
	Merge(A, left, right);
}

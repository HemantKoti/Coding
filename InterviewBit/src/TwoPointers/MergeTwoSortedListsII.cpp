/*
 * MergeTwoSortedListsII.cpp
 *
 *  Created on: May 14, 2018
 *      Author: HemantKo
 */

#include "../../include/interviewbit.h"

void merge(vector<int> &A, vector<int> &B)
{
	int i = 0, j = 0;
	vector<int> result;

	while (i < A.size() && j < B.size())
		result.push_back(A[i] <= B[j] ? A[i++] : B[j++]);

	while (i < A.size())
		result.push_back(A[i++]);

	while (j < B.size())
		result.push_back(B[j++]);

	A = result;
}

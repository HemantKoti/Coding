/*
 * SortedInsertPosition.cpp
 *
 *  Created on: Apr 20, 2018
 *      Author: HemantKo
 */

#include "../../include/interviewbit.h"

int searchInsert(vector<int> &A, int B)
{
	int start = 0, end = A.size() - 1;
	while (start <= end)
	{
		int mid = start + (end - start) / 2;
		if (B == A[mid])
			return mid;
		else if (B < A[mid])
			end = mid - 1;
		else
			start = mid + 1;
	}
	return start;
}

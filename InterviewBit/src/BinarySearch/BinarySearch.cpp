/*
 * BinarySearch.cpp
 *
 *  Created on: Apr 18, 2018
 *      Author: HemantKo
 */

#include "../../include/interviewbit.h"

int binarySearch(vector<int> &A, int element)
{
	int start = 0, end = A.size() - 1;
	while (start <= end)
	{
		int mid = start + (end - start) / 2;
		if (element == A[mid])
			return mid;
		else if (element < A[mid])
			end = mid - 1;
		else
			start = mid + 1;
	}
	return -1;
}

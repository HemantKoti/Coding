/*
 * MaximumAbsoluteDifference.cpp
 *
 *  Created on: Feb 10, 2018
 *      Author: HemantKo
 */

#include "../../include/interviewbit.h"

int maxArr(vector<int> &A)
{
	int maxDiff = INT_MIN;
	int max1 = INT_MIN, max2 = INT_MIN;
	int min1 = INT_MAX, min2 = INT_MAX;

	for (int i = 0; i < A.size(); i++)
	{
		max1 = max(max1, A[i] + i);
		max2 = max(max2, A[i] - i);
		min1 = min(min1, A[i] + i);
		min2 = min(min2, A[i] - i);
	}

	maxDiff = max(maxDiff, max2 - min2);
	maxDiff = max(maxDiff, max1 - min1);
	return maxDiff;
}

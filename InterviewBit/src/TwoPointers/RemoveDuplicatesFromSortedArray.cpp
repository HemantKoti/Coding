/*
 * RemoveDuplicatesFromSortedArray.cpp
 *
 *  Created on: May 14, 2018
 *      Author: HemantKo
 */

#include "../../include/interviewbit.h"

int removeDuplicates(vector<int> &A)
{
	int i = 0;
	for (int j = 1; j < A.size(); j++)
	{
		if (A[i] != A[j])
		{
			i++;
			A[i] = A[j];
		}
	}
	return i + 1;
}

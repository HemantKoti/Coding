/*
 * RemoveDuplicatesFromSortedArrayII.cpp
 *
 *  Created on: May 14, 2018
 *      Author: HemantKo
 */

#include "../../include/interviewbit.h"

int removeDuplicatesII(vector<int> &A)
{
	if (A.size() < 2)
		return A.size();

	int count = 0;
	for (int i = 0; i < A.size(); i++)
	{
		bool canCopy = !(i < A.size() - 2 && A[i] == A[i + 1] && A[i] == A[i + 2]);
		if (canCopy)
			A[count++] = A[i];
	}
	return count;
}

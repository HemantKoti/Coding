/*
 * CountElementOccurence.cpp
 *
 *  Created on: Apr 18, 2018
 *      Author: HemantKo
 */

#include "../../include/interviewbit.h"

int findCountUtil(const vector<int> &A, int element, bool isFirstSearch)
{
	int start = 0, end = A.size() - 1, resultidx = -1;
	while (start <= end)
	{
		int mid = start + (end - start) / 2;
		if (element == A[mid])
		{
			resultidx = mid;
			if (isFirstSearch)
				end = mid - 1;
			else
				start = mid + 1;
		}
		else if (element < A[mid])
			end = mid - 1;
		else
			start = mid + 1;
	}
	return resultidx;
}

int findCount(const vector<int> &A, int B)
{
	if (findCountUtil(A, B, false) == -1)
		return 0;
	else
		return findCountUtil(A, B, false) - findCountUtil(A, B, true) + 1;
}

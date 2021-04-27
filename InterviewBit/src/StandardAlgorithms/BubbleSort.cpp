/*
 * BubbleSort.cpp
 *
 *  Created on: Mar 4, 2018
 *      Author: HemantKo
 */

#include "../../include/interviewbit.h"

void BubbleSort(vector<int> &A)
{
	for (int i = 0; i < A.size() - 1; i++)
	{
		bool isSorted = true;
		for (int j = 0; j < A.size() - i - 1; j++)
		{
			if (A[j] > A[j + 1])
			{
				swap(&A[j], &A[j + 1]);
				isSorted = false;
			}
		}

		if (isSorted)
			break;
	}
}

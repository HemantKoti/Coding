/*
 * SelectionSort.cpp
 *
 *  Created on: Mar 4, 2018
 *      Author: HemantKo
 */

#include "../include/global.h"

void SelectionSort(vector<int> &A)
{
	for (int i = 0; i < A.size(); i++)
	{
		int minIndex = i;
		for (int j = i + 1; j < A.size(); j++)
		{
			if (A[j] < A[minIndex])
			{
				minIndex = j;
			}
		}

		if (minIndex != i)
		{
			swap(&A[i], &A[minIndex]);
		}
	}
}

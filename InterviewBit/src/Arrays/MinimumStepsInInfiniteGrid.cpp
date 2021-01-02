/*
 * MinimumStepsInInfiniteGrid.cpp
 *
 *  Created on: Feb 5, 2018
 *      Author: HemantKo
 */

#include "../../include/interviewbit.h"

int calculateDistance(int x1, int y1, int x2, int y2)
{
	return max(abs(x2 - x1), abs(y2 - y1));
}

int coverPoints(vector<int> &A, vector<int> &B)
{
	int minSteps = 0;
	for (int i = 0; i < A.size() - 1; i++)
	{
		minSteps += calculateDistance(A[i], B[i], A[i + 1], B[i + 1]);
	}
	return minSteps;
}

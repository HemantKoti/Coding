/*
 * WaveArray.cpp
 *
 *  Created on: Feb 26, 2018
 *      Author: HemantKo
 */

#include "../../include/interviewbit.h"

vector<int> wave(vector<int> &A)
{
	sort(A.begin(), A.end());
	vector<int> result;
	for (int i = 0; i < A.size(); i = i + 2)
	{
		// If size is odd push the last element and break
		if ((A.size() & 1) && i + 1 >= A.size())
		{
			result.push_back(A[i]);
		}
		else
		{
			result.push_back(A[i + 1]);
			result.push_back(A[i]);
		}
	}

	return result;
}

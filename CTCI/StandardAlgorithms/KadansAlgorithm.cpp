/*
 * KadansAlgorithm.cpp
 *
 *  Created on: Feb 18, 2018
 *      Author: HemantKo
 */

#include "../include/global.h"

Kadan &kadan(vector<int> &arr)
{
	Kadan result;
	int current_max = INT_MIN;
	for (int i = 0; i < arr.size(); i++)
	{
		if (current_max < 0)
		{
			current_max = arr[i];
			result.l = result.r = i;
		}
		else
		{
			current_max += arr[i];
			result.r = i;
		}
		result.max_sum = max(result.max_sum, current_max);
	}
	return result;
}

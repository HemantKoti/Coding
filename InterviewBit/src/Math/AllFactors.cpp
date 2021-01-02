/*
 * AllFactors.cpp
 *
 *  Created on: Apr 1, 2018
 *      Author: HemantKo
 */

#include "../../include/interviewbit.h"

vector<int> allFactors(int A)
{
	vector<int> result;
	for (int i = 1; i <= sqrt(A); i++)
	{
		if (A % i == 0)
		{
			result.push_back(i);
			if (i != sqrt(A))
			{
				result.push_back(A / i);
			}
		}
	}
	sort(result.begin(), result.end());
	return result;
}

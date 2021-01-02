/*
 * PrimeFactorization.cpp
 *
 *  Created on: Apr 26, 2018
 *      Author: HemantKo
 */

#include "../../include/interviewbit.h"

map<int, int> primeFactorization(int A)
{
	map<int, int> primeFactors;
	for (int i = 2; i <= sqrt(A); i++)
	{
		int frequency = 0;
		while (A % i == 0)
		{
			A /= i;
			frequency++;
		}
		primeFactors.insert(make_pair(i, frequency));
	}
	if (A != 1)
	{ // The last element will always be either 1 or the prime number remaining
		primeFactors.insert(make_pair(A, 1));
	}
	return primeFactors;
}

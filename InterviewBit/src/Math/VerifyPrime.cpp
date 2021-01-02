/*
 * VerifyPrime.cpp
 *
 *  Created on: Apr 2, 2018
 *      Author: HemantKo
 */

#include "../../include/interviewbit.h"

int isPrime(int A)
{
	for (int i = 2; i <= sqrt(A); i++)
	{
		if (A % i == 0)
			return 0;
	}
	return A == 0 || A == 1 ? 0 : 1;
}

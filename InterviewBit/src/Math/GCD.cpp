/*
 * ReverseInteger.cpp
 *
 *  Created on: Apr 4, 2018
 *      Author: HemantKo
 */

#include "../../include/interviewbit.h"

int gcd(int A, int B)
{
	while (B != 0)
	{
		int rem = A % B;
		A = B;
		B = rem;
	}
	return A;
}

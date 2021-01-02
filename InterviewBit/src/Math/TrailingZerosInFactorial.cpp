/*
 * TrailingZerosInFactorial.cpp
 *
 *  Created on: Apr 4, 2018
 *      Author: HemantKo
 */

#include "../../include/interviewbit.h"

int trailingZeroes(int A)
{
	int trailZeroes = 0;
	for (int i = 1; A / pow(5, i); trailZeroes += A / pow(5, i), i++)
		;
	return trailZeroes;
}

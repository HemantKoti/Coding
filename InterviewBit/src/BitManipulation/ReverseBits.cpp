/*
 * ReverseBits.cpp
 *
 *  Created on: Apr 30, 2018
 *      Author: HemantKo
 */

#include "../../include/interviewbit.h"

unsigned reverse(unsigned int A)
{
	unsigned reverse = A;
	int size = sizeof(A) * 8;
	while (A)
	{
		reverse <<= 1;
		reverse |= A & 1;
		A >>= 1;
		size--;
	}
	return reverse <<= size;
}

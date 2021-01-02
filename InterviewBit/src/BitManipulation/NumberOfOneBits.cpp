/*
 * ReverseBits.cpp
 *
 *  Created on: Apr 30, 2018
 *      Author: HemantKo
 */

#include "../../include/interviewbit.h"

int numSetBits(unsigned int A)
{
	unsigned count = 0;
	while (A)
	{
		count += A & 1;
		A >>= 1;
	}
	return count;
}

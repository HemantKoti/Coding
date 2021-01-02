/*
 * ImplementPowerFunction.cpp
 *
 *  Created on: Apr 20, 2018
 *      Author: HemantKo
 */

#include "../../include/interviewbit.h"

int pow(int x, int n, int d)
{
	if (x == 0)
	{
		return 0;
	}
	else if (n == 0)
	{
		return 1 % d;
	}

	long long y = x % d;
	long long rem = 1;
	while (n)
	{
		if (n & 1)
		{
			rem = (rem * y) % d;
			n--;
		}
		else
		{
			y = (y * y) % d;
			n /= 2;
		}
	}

	if (rem < 0)
	{
		rem = (d + rem) % d;
	}

	return rem;
}

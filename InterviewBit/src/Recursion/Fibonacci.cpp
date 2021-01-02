/*
 * Fibonacci.cpp
 *
 *  Created on: Mar 4, 2018
 *      Author: HemantKo
 */

#include "../../include/interviewbit.h"
#define MAX_SIZE 1000

int fib[MAX_SIZE]{-1};
int fibonacci(int n)
{
	if (n <= 1)
	{
		return n;
	}

	if (fib[n] != -1)
	{
		return fib[n];
	}

	fib[n] = fibonacci(n - 1) + fibonacci(n - 2);
	return fib[n];
}

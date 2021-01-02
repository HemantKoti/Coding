/*
 * PrimeNumbers.cpp
 *
 *  Created on: Apr 2, 2018
 *      Author: HemantKo
 */

#include "../../include/interviewbit.h"

vector<int> sieve(int A)
{
	vector<bool> isPrime(A + 1, true);
	isPrime[0] = isPrime[1] = false;
	for (int i = 2; i <= sqrt(A); i++)
		if (isPrime[i])
			for (int j = 2; j * i <= A; j++)
				isPrime[i * j] = false;

	vector<int> primes;
	for (int i = 0; i < A + 1; i++)
		if (isPrime[i])
			primes.push_back(i);

	return primes;
}

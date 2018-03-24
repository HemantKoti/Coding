/*
 * ModularExponentiation.cpp
 *
 *  Created on: Mar 5, 2018
 *      Author: HemantKo
 */

#include "Recursion.h"

long long modularExponentiation(long long x, int n, int m) {
	if (x == 0) {
		return 1;
	} else if (x & 1) {
		return (x % m * modularExponentiation(x, n - 1, m)) % m;
	} else {
		long long y = modularExponentiation(x, n / 2, m);
		return y * y % m;
	}
}

/*
 * Power.cpp
 *
 *  Created on: Mar 5, 2018
 *      Author: HemantKo
 */

#include "Recursion.h"

long long power(long long x, int n) {
	if (x == 0) {
		return 1;
	} else if (x & 1) {
		return x * power(x, n - 1);
	} else {
		long long y = x * power(x, n / 2);
		return y * y;
	}
}


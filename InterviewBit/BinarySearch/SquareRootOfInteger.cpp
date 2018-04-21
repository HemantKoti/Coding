/*
 * SquareRootOfInteger.cpp
 *
 *  Created on: Apr 20, 2018
 *      Author: HemantKo
 */

#include "../InterviewBit.h"

int sqrt(int A) {
	if (A == 0) {
		return 0;
	} else if (A == 1 || A == 2 || A == 3) {
		return 1;
	}

	long i = 0;
	long j = A / 2;
	while (i <= j) {
		long mid = (i + j) / 2;
		if (mid * mid == A)
			return (int) mid;
		if (mid * mid < A)
			i = mid + 1;
		else
			j = mid - 1;
	}

	return (int) j;
}


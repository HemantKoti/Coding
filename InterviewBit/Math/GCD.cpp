/*
 * ReverseInteger.cpp
 *
 *  Created on: Apr 4, 2018
 *      Author: HemantKo
 */

#include "../InterviewBit.h"

int gcd(int A, int B) {
	if (A < B) {
		swap(A, B);
	} else if (B == 0) {
		return A;
	}

	while (A % B != 0) {
		int temp = B;
		B = A - B;
		A = temp;
		if (A < B) {
			swap(A, B);
		}
	}
	return B;
}

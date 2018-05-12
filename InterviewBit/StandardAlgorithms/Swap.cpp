/*
 * Swap.cpp
 *
 *  Created on: Mar 4, 2018
 *      Author: HemantKo
 */

#include "../InterviewBit.h"

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}


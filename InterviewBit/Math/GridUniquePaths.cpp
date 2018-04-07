/*
 * GridUniquePaths.cpp
 *
 *  Created on: Apr 8, 2018
 *      Author: HemantKo
 */

#include "../InterviewBit.h"

int uniquePaths(int A, int B) {
	//	Note that you have to take m + n - 2 steps in total. You have to take (m - 1) steps going down and (n-1) steps going right.
	//	Let 0 denote a down step and 1 denote a right step.
	//	So we need to find out the number of strings of length m + n - 2 which have exactly m - 1 zeroes and n - 1 ones.
	//	Essentially we need to choose the positions of ‘1s’, and then ‘0s’ fall into the remaining positions.
	//	So, the answer becomes Choose(m+n-2, n - 1).
	if (A == 1 || B == 1) {
		return 1;
	}
	return choose(A + B - 2, A - 1);
}


/*
 * RepeatAndMissingNumberArray.cpp
 *
 *  Created on: Feb 11, 2018
 *      Author: HemantKo
 */

#include "../InterviewBit.h"

vector<int> repeatedNumber(const vector<int> &A) {
	int xor1;
	int set_bit_no;
	int repeating = 0, missing = 0;

	xor1 = A[0];

	for (int i = 1; i < A.size(); i++)
		xor1 = xor1 ^ A[i];

	for (int i = 1; i <= A.size(); i++)
		xor1 = xor1 ^ i;

	set_bit_no = xor1 & ~(xor1 - 1);

	for (int i = 0; i < A.size(); i++) {
		if (A[i] & set_bit_no)
			repeating ^= A[i];
		else
			missing ^= A[i];
	}
	for (int i = 1; i <= A.size(); i++) {
		if (i & set_bit_no)
			repeating ^= i;
		else
			missing ^= i;
	}

	vector<int> output;
	output.push_back(repeating);
	output.push_back(missing);

	return output;
}

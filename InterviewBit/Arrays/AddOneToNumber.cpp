/*
 * AddOneToNumber.cpp
 *
 *  Created on: Feb 5, 2018
 *      Author: HemantKo
 */

#include "../InterviewBit.h"

vector<int> plusOne(vector<int> &A) {
	vector<int> output;
	int carry = 1, remainder = 0;

	for (int i = A.size() - 1; i >= 0; i--) {
		A[i] += carry;
		if (A[i] >= 10) {
			remainder = A[i] - 10;
			carry = 1;
			output.push_back(remainder);
		} else {
			carry = 0;
			output.push_back(A[i]);
		}
	}

	if (carry == 1) {
		output.push_back(1);
	} else {
		while (output.back() == 0) {
			output.pop_back();
		}
	}

	reverse(output.begin(), output.end());
	return output;
}


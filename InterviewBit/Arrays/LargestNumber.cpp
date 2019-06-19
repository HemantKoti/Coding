/*
 * LargestNumber.cpp
 *
 *  Created on: Mar 29, 2018
 *      Author: HemantKo
 */

#include "../InterviewBit.h"

bool myCmp(int x, int y) {
	string a = to_string(x);
	string b = to_string(y);
	return a + b > b + a;
}

string largestNumber(const vector<int> &A) {
	vector<int> largest = A;
	sort(largest.begin(), largest.end(), myCmp);
	string result = "";
	bool isAllZeroes = true;
	for (int i = 0; i < largest.size(); i++) {
		if (largest[i] != 0) {
			isAllZeroes = false;
		}
		result += to_string(largest[i]);
	}
	return isAllZeroes ? "0" : result;
}


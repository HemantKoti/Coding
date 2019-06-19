/*
 * FizzBuzz.cpp
 *
 *  Created on: Apr 4, 2018
 *      Author: HemantKo
 */

#include "../InterviewBit.h"

vector<string> fizzBuzz(int A) {
	vector<string> result;
	for (int i = 1; i <= A; i++) {
		if (i % 15 == 0) {
			result.push_back("FizzBuzz");
		} else if (i % 5 == 0) {
			result.push_back("Buzz");
		} else if (i % 3 == 0) {
			result.push_back("Fizz");
		} else {
			result.push_back(to_string(i));
		}
	}
	return result;
}


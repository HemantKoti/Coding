/*
 * FindPhoneNumber.cpp
 *
 *  Created on: Jun 24, 2018
 *      Author: HemantKo
 */

#include "../InterviewBit.h"

bool checkFormat1(string str, int index) {
	for (int i = -3; index + i > -1 && index + i < str.size() && i <= 8; i++) {
		if (i == 0 && str[i + index] != '-') {
			return false;
		} else if (i == 4 && str[i + index] != '-') {
			return false;
		} else if (i != 0 && i != 4 && !isdigit(str[i + index])) {
			return false;
		}
	}

	return true;
}

bool checkFormat2(string str, int index) {
	for (int i = 1; index + i < str.size() && i <= 13; i++) {
		if (i == 4 && str[i + index] != ')') {
			return false;
		} else if (i == 5 && str[i + index] != ' ') {
			return false;
		} else if (i == 9 && str[i + index] != '-') {
			return false;
		} else if (i != 4 && i != 5 && i != 9 && !isdigit(str[i + index])) {
			return false;
		}
	}

	return true;
}

string findPhoneNumber(string str) {
	string phoneNumber = "NONE";
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '(' && checkFormat2(str, i)) {
			phoneNumber = str.substr(i, 14);
			return phoneNumber;
		} else if (str[i] == '-' && checkFormat1(str, i)) {
			phoneNumber = str.substr(i - 3, 12);
			return phoneNumber;
		}
	}

	return phoneNumber;
}

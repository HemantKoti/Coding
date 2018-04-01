/*
 * PalindromeInteger.cpp
 *
 *  Created on: Apr 2, 2018
 *      Author: HemantKo
 */

#include "../InterviewBit.h"

int isPalindrome(int A) {
	if (A < 0) {
		return 0;
	}
	int temp = A, rem = 0, reverse = 0;
	int numOfDigits = 0;
	while (A) {
		A /= 10;
		numOfDigits++;
	}
	A = temp;
	while (A) {
		int rem = A % 10;
		A /= 10;
		reverse += rem * pow(10, --numOfDigits);
	}

	return temp == reverse ? 1 : 0;
}


//int isPalindrome(int A) {
//    string str = to_string(A);
//    for (int i = 0, j = str.size() - 1; i <= j; i++, j--){
//        if(str[i] != str[j]){
//            return 0;
//        }
//    }
//    return 1;
//}


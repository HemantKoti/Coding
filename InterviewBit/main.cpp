//============================================================================
// Name        : InterviewBit.cpp
// Author      : Hemant Koti
// Version     :
// Copyright   : Your copyright notice
// Description : InterviewBit problems
//============================================================================

#include "InterviewBit.h"

int main() {
	ofstream errorLog("ErrorLogging/MyTrace.txt",
			ios_base::app | ios_base::out);
	try {
		//int arr[] { 1, 2 , 3, 4 };
		//vector<int> A(arr, arr + sizeof arr / sizeof arr[0]);
		int A = 7;
		vector<int> result = sieve(A);
		for (int i = 0; i < result.size(); i++)
			cout << result[i] << " ";
	} catch (exception & ex) {
		errorLog << ex.what() << endl;
	}

}


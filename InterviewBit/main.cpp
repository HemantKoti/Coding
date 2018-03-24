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
		int arr[] { 2, 4, 1, 6, 8, 5, 3, 7 };
		vector<int> A(arr, arr + sizeof arr / sizeof arr[0]);
		QuickSort(A, 0, A.size() - 1);
		for (int i = 0; i < A.size(); i++) {
			cout << A[i] << " ";
		}
	} catch (exception & ex) {
		errorLog << ex.what() << endl;
	}

}


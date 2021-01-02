//============================================================================
// Name        : InterviewBit.cpp
// Author      : Hemant Koti
// Version     :
// Copyright   : Your copyright notice
// Description : InterviewBit problems
//============================================================================

#include "../include/interviewbit.h"

int main()
{
	ofstream errorLog("Logging/trace.log", ios_base::app | ios_base::out);
	try
	{
		vector<int> A{4, 1, 2, 10};
		BubbleSort(A);
		for (auto &it : A)
			cout << it << " ";
	}
	catch (exception &ex)
	{
		errorLog << ex.what() << endl;
	}
}

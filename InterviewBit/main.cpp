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

		ListNode* head = NULL;
		for (int i = 0; i < 10; i++)
			insertInTheEnd(&head, i + 1);
		printList(head);
		deleteNodeKey(&head, 5);
		deleteNodeKey(&head, 6);
		printList(head);
	} catch (exception & ex) {
		errorLog << ex.what() << endl;
	}

}


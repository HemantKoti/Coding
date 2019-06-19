/*
 * PalindromeList.cpp
 *
 *  Created on: Jun 25, 2018
 *      Author: HemantKo
 */

#include "../InterviewBit.h"

int lPalin(ListNode* A) {
	if (A == NULL)
		return 0;

	ListNode* fast = A, *originalHead = A, *prev_middle;
	while (fast != NULL && fast->next != NULL) {
		prev_middle = A;
		A = A->next;
		fast = fast->next->next;
	}

	prev_middle->next = NULL;
	reverseLinkedList(&A);

	while (originalHead && A) {
		if (originalHead->val != A->val) {
			return 0;
		}
		originalHead = originalHead->next;
		A = A->next;
	}

	return 1;
}

/*
 * MergeTwoSortedLists.cpp
 *
 *  Created on: Jun 16, 2018
 *      Author: HemantKo
 */

#include "../InterviewBit.h"

ListNode* mergeTwoLists(ListNode* A, ListNode* B) {
	ListNode* head = NULL;

	if (A == NULL)
		return B;
	else if (B == NULL)
		return A;
	else if (A->val <= B->val) {
		head = A;
		head->next = mergeTwoLists(A->next, B);
	} else {
		head = B;
		head->next = mergeTwoLists(A, B->next);
	}

	return head;
}


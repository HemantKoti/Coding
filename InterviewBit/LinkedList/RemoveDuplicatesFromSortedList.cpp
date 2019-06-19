/*
 * RemoveDuplicatesFromSortedList.cpp
 *
 *  Created on: Jun 16, 2018
 *      Author: HemantKo
 */

#include "../InterviewBit.h"

ListNode* deleteDuplicates(ListNode* A) {
	ListNode* temp = A, *original = A;

	while (A != NULL) {
		if (temp->val != A->val) {
			temp = temp->next;
			temp->val = A->val;
		}
		A = A->next;
	}

	if (temp->next != NULL)
		temp->next = NULL;

	return original;
}


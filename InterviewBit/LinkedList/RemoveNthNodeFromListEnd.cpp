/*
 * RemoveNthNodeFromListEnd.cpp
 *
 *  Created on: Jun 17, 2018
 *      Author: HemantKo
 */

#include "../InterviewBit.h"

ListNode* removeNthFromEnd(ListNode* A, int B) {
	int length = listLength(A);
	B = B >= length ? length : B;

	ListNode* curr = A, *oHead = A, *prev = NULL, *next;
	for (int count = 0; A != NULL && count != B; count++, A = A->next)
		;

	while (A != NULL) {
		prev = curr;
		A = A->next;
		curr = curr->next;
	}

	next = curr->next;
	if (oHead == curr)
		oHead = next;
	else
		prev->next = next;
	free(curr);

	return oHead;
}

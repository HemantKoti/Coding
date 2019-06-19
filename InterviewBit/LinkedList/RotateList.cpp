/*
 * RotateList.cpp
 *
 *  Created on: Jun 17, 2018
 *      Author: HemantKo
 */

#include "../InterviewBit.h"

ListNode* rotateRight(ListNode* A, int B) {
	int length = listLength(A);
	B = B % length;

	ListNode* oHead = A, *curr = A, *next;
	for (int count = 0; A != NULL && count != B; count++, A = A->next)
		;

	if (A == NULL || B == 0)
		return oHead;

	while (A->next != NULL) {
		A = A->next;
		curr = curr->next;
	}

	next = curr->next;
	curr->next = NULL;
	A = next;

	while (next->next != NULL)
		next = next->next;
	next->next = oHead;

	return A;
}


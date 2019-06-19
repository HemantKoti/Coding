/*
 * ReverseLinkListII.cpp
 *
 *  Created on: Jun 3, 2018
 *      Author: HemantKo
 */

#include "../InterviewBit.h"

ListNode* reverseLinkedList(ListNode *headPtr) {
	ListNode *prev = NULL, *next;
	while (headPtr != NULL) {
		next = headPtr->next;
		headPtr->next = prev;
		prev = headPtr;
		headPtr = next;
	}
	return prev;
}

ListNode* reverseBetween(ListNode* A, int B, int C) {
	if (A == NULL || A->next == NULL || B == C)
		return A;

	ListNode *oHead = A, *revStart = NULL, *revStart_prev = NULL,
			*revEnd = NULL, *revEnd_next = NULL;

	for (int i = 1; i <= C && A != NULL; A = A->next, i++) {
		if (i < B)
			revStart_prev = A;
		else if (i == B)
			revStart = A;
		else if (i == C) {
			revEnd = A;
			revEnd_next = A->next;
		}
	}

	revEnd->next = NULL;
	revEnd = reverseLinkedList(revStart);

	if (revStart_prev != NULL)
		revStart_prev->next = revEnd;
	else
		oHead = revEnd;

	revStart->next = revEnd_next;
	return oHead;
}


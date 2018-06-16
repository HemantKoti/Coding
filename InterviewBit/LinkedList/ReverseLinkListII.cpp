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

ListNode* reverseBetween(ListNode* head, int B, int C) {
	if (head == NULL || head->next == NULL || B == C)
		return head;

	ListNode *original = head, *revStart = NULL, *revStart_prev = NULL,
			*revEnd = NULL, *revEnd_next = NULL;

	for (int i = 1; i <= C && head != NULL; head = head->next, i++) {
		if (i < B)
			revStart_prev = head;
		else if (i == B)
			revStart = head;
		else if (i == C) {
			revEnd = head;
			revEnd_next = head->next;
		}
	}

	revEnd->next = NULL;
	revEnd = reverseLinkedList(revStart);

	if (revStart_prev != NULL)
		revStart_prev->next = revEnd;
	else
		original = revEnd;

	revStart->next = revEnd_next;
	return original;
}


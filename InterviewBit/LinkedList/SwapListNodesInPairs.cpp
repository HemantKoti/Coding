/*
 * SwapListNodesInPairs.cpp
 *
 *  Created on: Jun 17, 2018
 *      Author: HemantKo
 */

#include "../InterviewBit.h"

void swapPairsUtils(ListNode** A, ListNode *X, ListNode *Y, ListNode* prevX, ListNode* prevY) {
	if (prevX != NULL)
		prevX->next = Y;
	else
		*A = Y;

	if (prevY != NULL)
		prevY->next = X;
	else
		*A = X;

	// Swap next pointers
	ListNode *temp = Y->next;
	Y->next = X->next;
	X->next = temp;
}

ListNode* swapPairs(ListNode* A) {
	ListNode* oHead = A, *prevX = NULL, *prevY = NULL;
	while (A != NULL) {
		prevY = A;

		if (A->next != NULL)
			swapPairsUtils(&oHead, A, A->next, prevX, prevY);

		prevX = A;
		A = A->next;
	}

	return oHead;
}


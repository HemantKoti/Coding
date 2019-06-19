/*
 * SwapNodesInLinkedList.cpp
 *
 *  Created on: May 24, 2018
 *      Author: HemantKo
 */

#include "../InterviewBit.h"

void swapNodes(ListNode** headPtr, int x, int y) {
	if (!searchElementInListIterative(*headPtr, x)
			|| !searchElementInListIterative(*headPtr, y))
		return;

	ListNode* tempX = *headPtr, *tempY = *headPtr, *prevX = *headPtr, *prevY =
			*headPtr;
	if (tempX->val == x)
		prevX = NULL;
	else if (tempY->val == y)
		prevY = NULL;

	for (; tempX != NULL && tempX->val != x; prevX = tempX, tempX = tempX->next)
		;

	for (; tempY != NULL && tempY->val != y; prevY = tempY, tempY = tempY->next)
		;

	if (prevX != NULL)
		prevX->next = tempY;
	else
		*headPtr = tempY;

	if (prevY != NULL)
		prevY->next = tempX;
	else
		*headPtr = tempX;

	// Swap next pointers
	ListNode *temp = tempY->next;
	tempY->next = tempX->next;
	tempX->next = temp;
}


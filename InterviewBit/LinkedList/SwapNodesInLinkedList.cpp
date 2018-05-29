/*
 * SwapNodesInLinkedList.cpp
 *
 *  Created on: May 24, 2018
 *      Author: HemantKo
 */

#include "../InterviewBit.h"

void swapNodes(LLNode** headPtr, int x, int y) {
	if (!searchElementInListIterative(*headPtr, x)
			|| !searchElementInListIterative(*headPtr, y))
		return;

	LLNode* tempX = *headPtr, *tempY = *headPtr, *prevX = *headPtr, *prevY =
			*headPtr;
	if (tempX->data == x)
		prevX = NULL;
	else if (tempX->data == y)
		prevY = NULL;

	for (; tempX != NULL && tempX->data != x;
			prevX = tempX, tempX = tempX->next)
		;

	for (; tempY != NULL && tempY->data != y;
			prevY = tempY, tempY = tempY->next)
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
	LLNode *temp = tempY->next;
	tempY->next = tempX->next;
	tempX->next = temp;
}
}


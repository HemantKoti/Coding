/*
 * IntersectionOfLinkedList.cpp
 *
 *  Created on: May 31, 2018
 *      Author: HemantKo
 */

#include "../InterviewBit.h"

ListNode* getIntersectionNode(ListNode* A, ListNode* B) {
	int lengthA = 0, lengthB = 0;
	ListNode* tempA = A, *tempB = B;
	while (A != NULL) {
		lengthA++;
		A = A->next;
	}

	while (B != NULL) {
		lengthB++;
		B = B->next;
	}

	if (lengthA > lengthB) {
		int diff = lengthA - lengthB;
		while (diff--)
			tempA = tempA->next;
	} else if (lengthB > lengthA) {
		int diff = lengthB - lengthA;
		while (diff--)
			tempB = tempB->next;
	}

	while (tempA != NULL) {
		if (tempA == tempB)
			return tempA;
		tempA = tempA->next;
		tempB = tempB->next;
	}

	return NULL;
}


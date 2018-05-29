/*
 * GetMiddleElementOfList.cpp
 *
 *  Created on: May 24, 2018
 *      Author: HemantKo
 */

#include "../InterviewBit.h"

int getMiddle(LLNode* head) {
	if (head == NULL)
		return -1;

	LLNode* fast = head;
	while (fast != NULL && fast->next != NULL) {
		head = head->next;
		fast = fast->next->next;
	}

	return head->data;
}


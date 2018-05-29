/*
 * DetectLoopInLinkedList.cpp
 *
 *  Created on: May 29, 2018
 *      Author: HemantKo
 */

#include "../InterviewBit.h"

LLNode* detectLoop(LLNode* head) {
	LLNode* fast = head;
	while (fast != NULL && fast->next != NULL) {
		if (fast == head)
			return head;
		head = head->next;
		fast = fast->next->next;
	}

	return NULL;
}

/*
 * CountLoopNodes.cpp
 *
 *  Created on: May 29, 2018
 *      Author: HemantKo
 */

#include "../InterviewBit.h"

int countLoopNodes(LLNode* head) {
	int count = 0;
	LLNode* temp = detectLoop(head);
	if (temp == NULL)
		return count;
	while (temp == head) {
		count++;
		temp = temp->next;
	}

	return count;
}


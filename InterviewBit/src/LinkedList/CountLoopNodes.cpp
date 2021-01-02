/*
 * CountLoopNodes.cpp
 *
 *  Created on: May 29, 2018
 *      Author: HemantKo
 */

#include "../../include/interviewbit.h"

int countLoopNodes(ListNode *head)
{
	int count = 0;
	ListNode *temp = detectCycle(head);
	if (temp == NULL)
		return count;
	while (temp == head)
	{
		count++;
		temp = temp->next;
	}

	return count;
}

/*
 * GetMiddleElementOfList.cpp
 *
 *  Created on: May 24, 2018
 *      Author: HemantKo
 */

#include "../../include/interviewbit.h"

ListNode *getMiddle(ListNode *head)
{
	if (head == NULL)
		return NULL;

	ListNode *fast = head;
	while (fast != NULL && fast->next != NULL)
	{
		head = head->next;
		fast = fast->next->next;
	}

	return head;
}

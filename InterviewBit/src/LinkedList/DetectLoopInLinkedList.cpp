/*
 * DetectLoopInLinkedList.cpp
 *
 *  Created on: May 29, 2018
 *      Author: HemantKo
 */

#include "../../include/interviewbit.h"

ListNode *detectCycle(ListNode *head)
{
	if (head == NULL || head->next == NULL)
	{
		return NULL;
	}

	ListNode *slow = head, *fast = head;

	while (slow != NULL && fast != NULL)
	{
		slow = slow->next;
		if (fast->next != NULL)
			fast = (fast->next)->next;
		else
			return NULL;
		if (slow == fast)
			break;
	}

	if (slow == NULL || fast == NULL)
	{
		return NULL;
	}

	while (head != slow)
	{
		head = head->next;
		slow = slow->next;
	}

	return head;
}

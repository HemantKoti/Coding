/*
 * ReorderList.cpp
 *
 *  Created on: Jun 3, 2018
 *      Author: HemantKo
 */

#include "../../include/interviewbit.h"

ListNode *splitList(ListNode *head)
{
	ListNode *fast = head;
	while (head != NULL && fast != NULL)
	{
		if (fast->next != NULL)
			fast = fast->next->next;
		else
			break;
		head = head->next;
	}
	ListNode *nextPtr = head->next;
	head->next = NULL;
	return nextPtr;
}

ListNode *reorderList(ListNode *head)
{
	if (head == NULL)
		return NULL;
	else if (head->next == NULL)
		return head;

	ListNode *middle = splitList(head), *original = head;
	reverseLinkedList(&middle);

	while (head != NULL && middle != NULL)
	{
		ListNode *hNext = head->next;
		ListNode *mNext = middle->next;
		head->next = middle;
		middle->next = hNext;
		head = hNext;
		middle = mNext;
	}

	return original;
}

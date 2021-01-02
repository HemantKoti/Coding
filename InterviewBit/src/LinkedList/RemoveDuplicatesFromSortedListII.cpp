/*
 * RemoveDuplicatesFromSortedListII.cpp
 *
 *  Created on: Jun 16, 2018
 *      Author: HemantKo
 */

#include "../../include/interviewbit.h"

ListNode *createNewNode(int data, ListNode *A)
{
	ListNode *temp = new ListNode(data);
	temp->next = A;
	return temp;
}

ListNode *deleteDuplicatesII(ListNode *A)
{
	ListNode *original = A, *temp = createNewNode(-1, A), *prev = temp;
	while (A)
	{
		while (A->next != NULL && prev->next->val == A->next->val)
			A = A->next;

		if (prev->next == A)
			prev = prev->next;
		else
			prev->next = A->next;

		A = A->next;
	}

	return temp->next;
}

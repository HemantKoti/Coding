/*
 * Implementation.cpp
 *
 *  Created on: May 20, 2018
 *      Author: HemantKo
 */

#include "../InterviewBit.h"

ListNode* createNewNode(int data) {
	ListNode* temp = new ListNode;
	temp->val = data;
	temp->next = NULL;
	return temp;
}

void insertInTheBeginning(ListNode** headPtr, int data) {
	ListNode* temp = createNewNode(data);
	temp->next = *headPtr;
	*headPtr = temp;
}

void insertAfter(ListNode** headPtr, int data) {
	if (*headPtr == NULL) {
		*headPtr = createNewNode(data);
		return;
	}
	ListNode* newNode = createNewNode(data);
	ListNode* temp = *headPtr;
	newNode->next = temp->next;
	temp->next = newNode;
}

void insertInTheEnd(ListNode** headPtr, int data) {
	if (*headPtr == NULL) {
		*headPtr = createNewNode(data);
		return;
	}
	ListNode* temp = *headPtr;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = createNewNode(data);
}

void printList(ListNode* head) {
	while (head != NULL) {
		cout << head->val << " ";
		head = head->next;
	}
	cout << endl;
}

void deleteList(ListNode** head) {
	while (*head != NULL) {
		ListNode* temp = *head;
		*head = (*head)->next;
		free(temp);
	}
}

void deleteNodeKey(ListNode** headPtr, int data) {
	ListNode* temp = *headPtr, *prev = NULL;

	if (temp != NULL && temp->val == data) {
		*headPtr = temp->next;
		free(temp);
		return;
	}

	while (temp != NULL && temp->val != data) {
		prev = temp;
		temp = temp->next;
	}

	if (temp == NULL)
		return;

	prev->next = temp->next;
	free(temp);
}

void deleteNodePosition(ListNode** headPtr, int position) {
	if (*headPtr == NULL)
		return;

	ListNode* temp = *headPtr;
	if (position == 0) {
		*headPtr = temp->next;
		free(temp);
		return;
	}

	for (int i = 0; i < position - 1 && temp != NULL; i++, temp = temp->next)
		;

	if (temp == NULL || temp->next == NULL)
		return;

	ListNode* nextNode = temp->next->next;
	free(temp->next);
	temp->next = nextNode;
}

int linkedListLengthIterative(ListNode* head) {
	int count = 0;
	while (head != NULL) {
		count++;
		head = head->next;
	}
	return count;
}

int linkedListLengthRecursive(ListNode* head) {
	if (head == NULL)
		return 0;
	return 1 + linkedListLengthRecursive(head->next);
}

bool searchElementInListIterative(ListNode* head, int data) {
	while (head != NULL) {
		if (head->val == data)
			return true;
		head = head->next;
	}

	return false;
}

bool searchElementInListRecursive(ListNode* head, int data) {
	if (head == NULL)
		return false;
	else if (head->val == data)
		return true;

	return searchElementInListRecursive(head->next, data);
}

int getNthNodeLinkedList(ListNode* head, int position) {
	int count = 0;
	while (head != NULL) {
		if (count == position)
			return head->val;
		head = head->next;
		count++;
	}

	return -1;
}

int getNthNodeFromEndLinkedList(ListNode* head, int position) {

	ListNode* temp = head;
	for (int count = 0; head != NULL && count != position;
			count++, head = head->next)
		;

	if (head == NULL)
		return -1;

	while (head != NULL) {
		head = head->next;
		temp = temp->next;
	}

	return temp->val;
}

void reverseLinkedList(ListNode** headPtr) {
    ListNode *prev = NULL, *curr = *headPtr, *next;
	while (curr != NULL) {
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	*headPtr = prev;
}

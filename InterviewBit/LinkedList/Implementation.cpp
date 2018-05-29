/*
 * Implementation.cpp
 *
 *  Created on: May 20, 2018
 *      Author: HemantKo
 */

#include "../InterviewBit.h"

LLNode* createNewNode(int data) {
	LLNode* temp = new LLNode;
	temp->data = data;
	temp->next = NULL;
	return temp;
}

void insertInTheBeginning(LLNode** headPtr, int data) {
	LLNode* temp = createNewNode(data);
	temp->next = *headPtr;
	*headPtr = temp;
}

void insertAfter(LLNode** headPtr, int data) {
	if (*headPtr == NULL) {
		*headPtr = createNewNode(data);
		return;
	}
	LLNode* newNode = createNewNode(data);
	LLNode* temp = *headPtr;
	newNode->next = temp->next;
	temp->next = newNode;
}

void insertInTheEnd(LLNode** headPtr, int data) {
	if (*headPtr == NULL) {
		*headPtr = createNewNode(data);
		return;
	}
	LLNode* temp = *headPtr;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = createNewNode(data);
}

void printList(LLNode* head) {
	while (head != NULL) {
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}

void deleteList(LLNode** head) {
	while (*head != NULL) {
		LLNode* temp = *head;
		*head = (*head)->next;
		free(temp);
	}
}

void deleteNodeKey(LLNode** headPtr, int data) {
	LLNode* temp = *headPtr, *prev = NULL;

	if (temp != NULL && temp->data == data) {
		*headPtr = temp->next;
		free(temp);
		return;
	}

	while (temp != NULL && temp->data != data) {
		prev = temp;
		temp = temp->next;
	}

	if (temp == NULL)
		return;

	prev->next = temp->next;
	free(temp);
}

void deleteNodePosition(LLNode** headPtr, int position) {
	if (*headPtr == NULL)
		return;

	LLNode* temp = *headPtr;
	if (position == 0) {
		*headPtr = temp->next;
		free(temp);
		return;
	}

	for (int i = 0; i < position - 1 && temp != NULL; i++, temp = temp->next)
		;

	if (temp == NULL || temp->next == NULL)
		return;

	LLNode* nextNode = temp->next->next;
	free(temp->next);
	temp->next = nextNode;
}

int linkedListLengthIterative(LLNode* head) {
	int count = 0;
	while (head != NULL) {
		count++;
		head = head->next;
	}
	return count;
}

int linkedListLengthRecursive(LLNode* head) {
	if (head == NULL)
		return 0;
	return 1 + linkedListLengthRecursive(head->next);
}

bool searchElementInListIterative(LLNode* head, int data) {
	while (head != NULL) {
		if (head->data == data)
			return true;
		head = head->next;
	}

	return false;
}

bool searchElementInListRecursive(LLNode* head, int data) {
	if (head == NULL)
		return false;
	else if (head->data == data)
		return true;

	return searchElementInListRecursive(head->next, data);
}

int getNthNodeLinkedList(LLNode* head, int position) {
	int count = 0;
	while (head != NULL) {
		if (count == position)
			return head->data;
		head = head->next;
		count++;
	}

	return -1;
}

int getNthNodeFromEndLinkedList(LLNode* head, int position) {

	LLNode* temp = head;
	for (int count = 0; head != NULL && count != position;
			count++, head = head->next)
		;

	if (head == NULL)
		return -1;

	while (head != NULL) {
		head = head->next;
		temp = temp->next;
	}

	return temp->data;
}

void reverseLinkedList(LLNode** headPtr) {
	LLNode* prev = NULL, *curr = *headPtr, *temp = *headPtr;
	while (curr != NULL) {
		temp = curr->next;
		temp->next = prev;
		prev = curr;
		curr = temp;
	}
	*headPtr = prev;
}

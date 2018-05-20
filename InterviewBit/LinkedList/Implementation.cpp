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

void deleteList(LLNode* head) {
	while (head != NULL) {
		LLNode* temp = head;
		head = head->next;
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

	for (int i = 0; i < position - 1 && temp != NULL; i++, temp = temp->next);

	if (temp == NULL || temp->next == NULL)
		return;

	LLNode* nextNode = temp->next->next;
	free(temp->next);
	temp->next = nextNode;
}

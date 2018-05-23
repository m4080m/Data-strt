#include<stdio.h>
#include<stdlib.h>
#include"Deque.h"

void DequeInit(Deque * pdeq){
	pdeq->head = NULL;
	pdeq->tail = NULL;
}

int DQIsEmpty(Deque * pdeq){
	if(pdeq->head == NULL && pdeq->tail == NULL){
		return TRUE;
	}
	else return FALSE;
}


void DQAddFirst(Deque * pdeq, Data data){
	Node *newNode = (Node *)malloc(sizeof(Node));
	newNode->data = data;
	if(pdeq->head == NULL && pdeq->tail == NULL){
		pdeq->head = newNode;
		pdeq->tail = newNode;
		pdeq->head->next = newNode;
		pdeq->tail->prev = newNode;
	}
	else{
		newNode->next = pdeq->head;
		pdeq->head->prev = newNode;
		pdeq->head = newNode;
	}
}

void DQAddLast(Deque * pdeq, Data data){
	Node *newNode = (Node *)malloc(sizeof(Node));
	newNode->data = data;
	if(pdeq->head == NULL && pdeq->tail == NULL){
		pdeq->head = newNode;
		pdeq->tail = newNode;
		pdeq->head->next = newNode;
		pdeq->tail->prev = newNode;
	}
	else{
		newNode->prev = pdeq->tail;
		pdeq->tail->next = newNode;
		pdeq->tail = newNode;
	}
}


Data DQRemoveFirst(Deque * pdeq){
	Data data = pdeq->head->data;
	if(pdeq->head == pdeq->tail){
		free(pdeq->head);
		pdeq->head = NULL;
		pdeq->tail = NULL;
	}
	else{
		Node *temp;
		temp = pdeq->head;
		pdeq->head = pdeq->head->next;
		pdeq->head->prev = NULL;
		free(temp);
	}
	return data;
}

Data DQRemoveLast(Deque * pdeq){
	Data data = pdeq->tail->data;
	if(pdeq->head == pdeq->tail){
		free(pdeq->tail);
		pdeq->head = NULL;
		pdeq->tail = NULL;
	}
	else{
		Node *temp;
		temp = pdeq->tail;
		pdeq->tail = pdeq->tail->prev;
		pdeq->tail->next = NULL;
		free(temp);
	}
	return data;
}


Data DQGetFirst(Deque * pdeq){
	return pdeq->head->data;
}

Data DQGetLast(Deque * pdeq){
	return pdeq->tail->data;
}

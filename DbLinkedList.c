#include<stdio.h>
#include<stdlib.h>
#include "DbLinkedList.h"

void ListInit(List *plist){
	plist->head=NULL;
	plist->tail=NULL;
	Node * dummyNodeHead=(Node*)malloc(sizeof(Node));
	dummyNodeHead->data=NULL;
	plist->head=dummyNodeHead;
	Node * dummyNodeTail=(Node*)malloc(sizeof(Node));
	dummyNodeTail->data=NULL;
	plist->tail=dummyNodeTail;
	plist->head->next=plist->tail;
	plist->tail->prev=plist->head;
	plist->cur=NULL;
	plist->numOfData=0;
}

void LInsert(List *plist, LData data){
	Node * newNode=(Node*)malloc(sizeof(Node));
	newNode->data=data;
	newNode->prev=plist->tail->prev;
	plist->tail->prev->next=newNode;
	plist->tail->prev=newNode;
	newNode->next=plist->tail;
	(plist->numOfData)++;
}

int LFirst(List *plist, LData *pdata){
	if(plist->head->next==plist->tail)
		return FALSE;
	else{
		plist->cur=plist->head->next;
		*pdata=plist->cur->data;
		return TRUE;
	}
}

int LNext(List *plist, LData *pdata){
	if(plist->cur==plist->tail)
		return FALSE;
	else{
		plist->cur=plist->cur->next;
		*pdata=plist->cur->data;
		return TRUE;
	}
}

LData LDelete(List *plist){
	Node *deleteNode=plist->cur;
	LData rdata=deleteNode->data;
	deleteNode->prev->next=deleteNode->next;
	deleteNode->next->prev=deleteNode->prev;
	plist->cur=deleteNode->prev;
	free(deleteNode);
	(plist->numOfData)--;
	return rdata;
}

void LClear(List *plist){
	plist->cur=plist->head->next;
	while(plist->cur!=plist->tail){
		Node *tempDelete=plist->cur;
		plist->cur=plist->cur->next;
		free(tempDelete);
	}
	plist->head->next=plist->tail;
	plist->tail->prev=plist->head;
}

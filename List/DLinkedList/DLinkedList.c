#include<stdio.h>
#include<stdlib.h>
#include "DLinkedList.h"

void ListInit(List *plist){
	plist->head=NULL;
	plist->tail=NULL;
	plist->cur=NULL;
	plist->numOfData=0;
}

void LInsert(List *plist, LData data){
	Node * newNode=(Node*)malloc(sizeof(Node));
	newNode->data=data;
	newNode->next=NULL;
	if(plist->head==NULL)
		plist->head=newNode;
	else
		plist->tail->next=newNode;
	plist->tail=newNode;
	(plist->numOfData)++;
}

int LFirst(List *plist, LData *pdata){
	if(plist->head->next==NULL)
		return FALSE;
	else{
		plist->before=plist->head;
		plist->cur=plist->head->next;
		*pdata=plist->cur->data;
		return TRUE;
	}
}

int LNext(List *plist, LData *pdata){
	if(plist->cur->next==NULL)
		return FALSE;
	else{
		plist->before=plist->cur;
		plist->cur=plist->cur->next;
		*pdata=plist->cur->data;
		return TRUE;
	}
}

LData LDelete(List *plist){
	Node *deleteNode=plist->cur;
	LData rdata=deleteNode->data;
	plist->before->next=plist->cur->next;
	plist->cur=plist->before;
	free(deleteNode);
	(plist->numOfData)--;
	return rdata;
}

void LClear(List *plist){
	plist->cur=plist->head->next;
	while(plist->cur->next!=NULL){
		Node *tempDelete=plist->cur;
		plist->cur=plist->cur->next;
		free(tempDelete);
	}
	free(plist->cur);
	plist->head->next=NULL;
	plist->tail=plist->head;
}

void SetSortRule(List *plist, int (*comp)(LData d1, LData d2)){
	plist->comp = comp;
}

void SInsert(List *plist, LData data){
	Node * newNode = (Node*)malloc(sizeof(Node));
	Node * pred = plist->head;
	newNode->data = data;
	
	while (pred->next != NULL && plist->comp(pred->next->data, data) == 0){
		pred = pred->next;
	}
	
	newNode->next = pred->next;
	pred->next = newNode;
	(plist->numOfData)++;
}

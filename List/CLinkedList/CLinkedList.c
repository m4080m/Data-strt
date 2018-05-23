#include<stdio.h>
#include<stdlib.h>
#include "CLinkedList.h"

void ListInit(List *plist){
	plist->tail=NULL;
	plist->cur=NULL;
	plist->numOfData=0;
}

void LInsert(List *plist, LData data){
	Node * newNode=(Node*)malloc(sizeof(Node));
	newNode->data=data;
	if(plist->tail==NULL){
		plist->tail=newNode;
		newNode->next=newNode;
	}
	else{
		newNode->next=plist->tail->next;
		plist->tail->next=newNode;
		plist->tail=newNode;
	}
	(plist->numOfData)++;
}

int LFirst(List *plist, LData *pdata){
	if(plist->numOfData==0)
		return FALSE;
	else{
		plist->before=plist->tail;
		plist->cur=plist->tail->next;
		*pdata=plist->cur->data;
		return TRUE;
	}
}

int LNext(List *plist, LData *pdata){
	if(plist->tail==NULL)
		return FALSE;
	if(plist->before!=plist->cur){
		plist->before=plist->cur;
		plist->cur=plist->cur->next;
		*pdata=plist->cur->data;
		if(plist->cur==plist->tail->next)
			return FALSE;
		return TRUE;
	}
	else{
		plist->cur=plist->cur->next;
		*pdata=plist->cur->data;
		return TRUE;
	}
}

LData LDelete(List *plist){
	Node *deleteNode=plist->cur;
	LData rdata=deleteNode->data;
	if(plist->cur==plist->before){
		free(plist->cur);
		plist->tail=NULL;
		plist->cur=NULL;
		plist->numOfData=0;
	}
	else{
		plist->before->next=plist->cur->next;
		plist->cur=plist->before;
		if(plist->tail==deleteNode)
			plist->tail=plist->before;
		free(deleteNode);
		(plist->numOfData)--;
	}
	return rdata;
}

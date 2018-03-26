#include <stdio.h>
#include<stdlib.h>
#include "DLinkedList.h"

Node *newNode=NULL;
LData readData;
LData curData;
LData targetData;

List myList;

void ListInit(List *plist){
	plist->head=NULL;
	plist->tail=NULL;
	plist->cur=NULL;
	plist->numOfData=0;
}

void LInsert(List *plist, LData data){
	newNode=(Node*)malloc(sizeof(Node));
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

void PrintList(){
	if(!LFirst(&myList,&curData))
		printf("�����Ͱ� ������� �ʾҽ��ϴ�.");
	else{
		printf("List: ");
		printf("%d ",curData);
		while(LNext(&myList,&curData)){
			printf("%d ",curData);
		}
	}
	printf("\n\n");
}

void Input(){
	while(1){
		scanf("%d",&readData);
		if(readData<1)break;
		LInsert(&myList,readData);
	}
}

void Delete(){
	scanf("%d",&targetData);
	if(LFirst(&myList,&curData)){
		if(curData==targetData)
			LDelete(&myList);
		while(LNext(&myList,&curData)){
			if(curData==targetData)
				LDelete(&myList);
		}
	}
}

void Init(){
	ListInit(&myList);
	LInsert(&myList,NULL);
}

void ext(){
	free(myList.head);
}
void mainloop(){
	system("cls");
	PrintList();
	printf("1. Input\n2. Delete\n3. Delete all\n4. exit\n��");
	int num;
	scanf("%d",&num);
	switch(num){
		case 1:
			printf("�ڿ����� �Է����ּ���, �ڿ����� �ƴ� ������ �Է��� �� �Է��� ����˴ϴ�.\n��");
			Input();
			break;
		case 2:
			printf("����Ʈ ������ ������ �ڿ����� �Է����ּ���.\n��");
			Delete();
			break;
		case 3:
			LClear(&myList);
			break;
		case 4:
			ext();
			break;
	}
	if(num!=4)mainloop();
	return;
}
int main(){
	Init();
	mainloop();
}

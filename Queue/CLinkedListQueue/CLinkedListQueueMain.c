#include <stdio.h>
#include <stdlib.h>
#include "CLinkedListQueue.h"

LData readData;
LData curData;
LData targetData;

List myList;

int num;

void PrintList(){
	if(!LFirst(&myList,&curData))
		printf("데이터가 저장되지 않았습니다.");
	else{
		printf("Queue: ");
		printf("%d ",curData);
		while(LNext(&myList,&curData)){
			printf("%d ",curData);
		}
	}
	printf("\n\n");
}

int Enqueue(){
	scanf("%d",&readData);
	LInsert(&myList,readData);
}

LData Dequeue(){
	return LDelete(&myList);
}

void Init(){
	ListInit(&myList);
}

void LClear(List *plist){
	if(LFirst(&myList,&curData)){
			LDelete(&myList);
		while(LNext(&myList,&curData)){
			LDelete(&myList);
		}
	}
}

void mainloop(){
	system("cls");
	//PrintList();
	if(num==2){
		printf("Pop: %d\n",Dequeue());
	}
	printf("1. Input\n2. Delete\n3. Delete all\n4. exit\n▶");
	scanf("%d",&num);
	switch(num){
		case 1:
			printf("Input:\n▶");
			Enqueue();
			break;
		case 2:
			break;
		case 3:
			LClear(&myList);
			break;
		case 4:
			break;
	}
	if(num!=4)mainloop();
	return;
}
int main(){
	Init();
	mainloop();
}

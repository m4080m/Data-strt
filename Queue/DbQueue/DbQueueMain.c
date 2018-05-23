#include <stdio.h>
#include <stdlib.h>
#include "DbQueue.h"

LData readData;
LData curData;
LData targetData;

List myList;

int num;

void PrintList(){
	if(!LFirst(&myList,&curData))
		printf("데이터가 저장되지 않았습니다.");
	else{
		printf("List: ");
		printf("%d ",curData);
		while(LNext(&myList,&curData)){
			printf("%d ",curData);
		}
	}
	printf("\n\n");
}

void Enqueue(){
	scanf("%d",&readData);
	LInsert(&myList,readData);
}

LData Dequeue(){
	return LDelete(&myList);
}

void Init(){
	ListInit(&myList);
}

void mainloop(){
	system("cls");
	if(num == 2){
		printf("Pop: %d\n",Dequeue());
	}
	PrintList();
	printf("1. Input\n2. Delete\n3. Delete all\n4. exit\n▶");
	scanf("%d",&num);
	switch(num){
		case 1:
			printf("정수를 입력해주세요.\n▶");
			Enqueue();
			break;
		case 2:
			break;
		case 3:
			LClear(&myList);
			break;
		case 4:
			LClear(&myList);
			break;
	}
	if(num!=4)mainloop();
	return;
}
int main(){
	Init();
	mainloop();
}

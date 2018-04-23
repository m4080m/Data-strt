#include <stdio.h>
#include <stdlib.h>
#include "DLinkedList.h"

LData readData;
LData curData;
LData targetData;

List myList;

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
				printf("V");
		}
	}
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
	PrintList();
	printf("1. Input\n2. Delete\n3. Delete all\n4. exit\n▶");
	int num, _sortNum;
	scanf("%d",&num);
	switch(num){
		case 1:
			printf("자연수를 입력해주세요, 자연수가 아닌 정수를 입력할 시 입력이 종료됩니다.\n▶");
			Input();
			break;
		case 2:
			printf("리스트 내에서 삭제할 자연수를 입력해주세요.\n▶");
			Delete();
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

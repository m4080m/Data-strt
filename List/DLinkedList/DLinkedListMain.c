#include <stdio.h>
#include <stdlib.h>
#include "DLinkedList.h"

LData readData;
LData curData;
LData targetData;

List myList;

int CompareUp(LData d1, LData d2){
	if(d1 < d2)
		return 0;
	else
		return 1;
}

int CompareDown(LData d1, LData d2){
	if(d1 > d2)
		return 0;
	else
		return 1;
}

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
		}
	}
}

void Init(){
	ListInit(&myList);
	LInsert(&myList,0);
}

void ext(){
	free(myList.head);
}

void Sort(int sortNum){
	if(sortNum == 1)
		SetSortRule(&myList, CompareUp);
	else if (sortNum == 2)
		SetSortRule(&myList, CompareDown);
	if(LFirst(&myList,&curData)){
		LDelete(&myList);
		SInsert(&myList, curData);
		while(LNext(&myList,&curData)){
			LDelete(&myList);
			SInsert(&myList, curData); //
			myList.cur=myList.cur->next;
		}
	}
}

void mainloop(){
	system("cls");
	PrintList();
	printf("1. Input\n2. Sort\n3. Delete\n4. Delete all\n5. exit\n▶");
	int num, _sortNum;
	scanf("%d",&num);
	switch(num){
		case 1:
			printf("자연수를 입력해주세요, 자연수가 아닌 정수를 입력할 시 입력이 종료됩니다.\n▶");
			Input();
			break;
		case 2:
			printf("오름차순 정렬 시 1, 내림차순 정렬 시 2를 입력해주세요.\n▶");
			scanf("%d",&_sortNum);
			Sort(_sortNum);
			break;
		case 3:
			printf("리스트 내에서 삭제할 자연수를 입력해주세요.\n▶");
			Delete();
			break;
		case 4:
			LClear(&myList);
			break;
		case 5:
			ext();
			break;
	}
	if(num!=5)mainloop();
	return;
}
int main(){
	Init();
	mainloop();
}

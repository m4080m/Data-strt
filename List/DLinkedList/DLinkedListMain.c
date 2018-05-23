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
	printf("1. Input\n2. Sort\n3. Delete\n4. Delete all\n5. exit\n��");
	int num, _sortNum;
	scanf("%d",&num);
	switch(num){
		case 1:
			printf("�ڿ����� �Է����ּ���, �ڿ����� �ƴ� ������ �Է��� �� �Է��� ����˴ϴ�.\n��");
			Input();
			break;
		case 2:
			printf("�������� ���� �� 1, �������� ���� �� 2�� �Է����ּ���.\n��");
			scanf("%d",&_sortNum);
			Sort(_sortNum);
			break;
		case 3:
			printf("����Ʈ ������ ������ �ڿ����� �Է����ּ���.\n��");
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

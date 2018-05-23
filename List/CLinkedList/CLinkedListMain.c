#include <stdio.h>
#include <stdlib.h>
#include "DLinkedList.h"

LData readData;
LData curData;
LData targetData;

List myList;

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
	printf("1. Input\n2. Delete\n3. Delete all\n4. exit\n��");
	int num, _sortNum;
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
			break;
	}
	if(num!=4)mainloop();
	return;
}
int main(){
	Init();
	mainloop();
}

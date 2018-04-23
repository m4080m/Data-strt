#include<stdio.h>
#include<stdlib.h>

int *arr;
int size=0;

void PrintList(){
	if(size==0)
		printf("데이터가 저장되지 않았습니다.");
	else{
		printf("List: ");
		int i;
		for(i=0;i<size;i++)
			printf("%d ",arr[i]);
	}
	printf("\n\n");
}

void Input(){
	int readData;
	while(1){
		scanf("%d",&readData);
		if(readData<1)break;
		arr = (int *)realloc(arr,(size+1)*sizeof(int));
		arr[size]=readData;
		size++;
	}
}
void Delete(){
	int n;
	scanf("%d",&n);
	if(n>size){
		arr = (int *)realloc(arr,0*sizeof(int));
		size=0;
	}
	else{
		arr = (int *)realloc(arr,(size-n)*sizeof(int));
		size-=n;
	}
}
void Clear(){
	arr = (int *)realloc(arr,0*sizeof(int));
	size=0;
}
void mainloop(){
	system("cls");
	PrintList();
	printf("1. Input\n2. Delete\n3. Delete all\n4. exit\n▶");
	int num;
	scanf("%d",&num);
	switch(num){
		case 1:
			printf("자연수를 입력해주세요, 자연수가 아닌 정수를 입력할 시 입력이 종료됩니다.\n▶");
			Input();
			break;
		case 2:
			printf("뒤에서부터 삭제할 데이터의 개수를 입력해주세요.\n▶");
			Delete();
			break;
		case 3:
			Clear();
			break;
		case 4:
			break;
	}
	if(num!=4)mainloop();
	return;
}
int main(){
	mainloop();
}

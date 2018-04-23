#include<stdio.h>
#include<stdlib.h>

int *arr;
int size=0;

void PrintList(){
	if(size==0)
		printf("�����Ͱ� ������� �ʾҽ��ϴ�.");
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
	printf("1. Input\n2. Delete\n3. Delete all\n4. exit\n��");
	int num;
	scanf("%d",&num);
	switch(num){
		case 1:
			printf("�ڿ����� �Է����ּ���, �ڿ����� �ƴ� ������ �Է��� �� �Է��� ����˴ϴ�.\n��");
			Input();
			break;
		case 2:
			printf("�ڿ������� ������ �������� ������ �Է����ּ���.\n��");
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

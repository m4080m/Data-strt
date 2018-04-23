#include<stdio.h>
#include<string.h>
#define NUMBER 0
#define OPERATION_PRIORITY_1 1
#define OPERATION_PRIORITY_2 2

typedef struct{
	int type;
	int value;
	char operation;
}Data;

Data Pop(Data *stack, int *top);
Data Top(Data *stack, int *top);
void Push(Data *stack, int *top, Data k);
void PostFix(Data *stack, Data *arr, int *top, int *size, Data k);

Data postFixStack[100];
int postFixTop=-1;
Data postFixResult[100];
int postFixSize=0;

int main(){
	char str[100];
	scanf("%s",str);
	int len=strlen(str);
	for(int i=0;i<len;i++){
		if('0'<=str[i]&&str[i]<='9'){
			Data newData;
			newData.type=NUMBER;
			newData.value=str[i]-'0';
		}
		else if(str[i]=='+'||str[i]=='-'||str[i]=='x'||str[i]=='/'||str[i]=='%'){
			Data newData;
			newData.type=OPERATION_PRIORITY_1;
			newData.operation=str[i];
		}
		else if(str)
		PostFix(postFixStack, postFixResult, &postFixTop, &postFixSize, newData);
	}
}

Data Pop(Data *stack, int *top){
	if(*top == -1){
		return 0;
	}
	else{
		(*top)--;
		return stack[(*top)+1];
	}
}

Data Top(Data *stack, int *top){
	if(*top == -1){
		return 0;
	}
	else return stack[*top];
}

void Push(Data *stack, int *top, Data k){
	(*top)++;
	stack[*top]=k;
}

void PostFix(Data *stack, Data *arr, int *top, int *size, Data k){
	if(k.type==NUMBER){
		arr[*top]=k.value;
		(*size)++;
	}
	else if(k.type==OPERATION){
		
	}
}

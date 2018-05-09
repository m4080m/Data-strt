#include<stdio.h>
#include<string.h>
#define NUMBER 0
#define OPERATION_PRIORITY_DUMMY -1
#define OPERATION_PRIORITY_1 1
#define OPERATION_PRIORITY_2 2
#define OPERATION_PRIORITY_3 3

typedef struct{
	int type;
	int value;
	char operation;
}Data;

Data Pop(Data *stack, int *top);
Data Top(Data *stack, int *top);
void Push(Data *stack, int *top, Data k);
void PostFix(Data *stack, Data *arr, int *top, int *size, Data k);
void PostFixFinish(Data *stack, Data *arr, int *top, int *size);

Data postFixStack[100];
int postFixTop=-1;
Data postFixResult[100];
int postFixSize=0;

Data Dummy={OPERATION_PRIORITY_DUMMY,0,0};

int main(){
	char str[100];
	scanf("%s",str);
	int len=strlen(str);
	for(int i=0;i<len;i++){
		Data newData;
		if('0'<=str[i]&&str[i]<='9'){
			newData.type=NUMBER;
			newData.value=str[i]-'0';
		}
		else if(str[i]=='+'||str[i]=='-'){
			newData.type=OPERATION_PRIORITY_2;
			newData.operation=str[i];
		}
		else if(str[i]=='*'||str[i]=='/'||str[i]=='%'){
			newData.type=OPERATION_PRIORITY_3;
			newData.operation=str[i];
		}
		else if(str[i]=='('||str[i]==')'){
			newData.type=OPERATION_PRIORITY_1;
			newData.operation=str[i];
		}
		PostFix(postFixStack, postFixResult, &postFixTop, &postFixSize, newData);
	}
	PostFixFinish(postFixStack, postFixResult, &postFixTop, &postFixSize);
	for(int i=0;i<postFixSize;i++){
		if(postFixResult[i].type==NUMBER){
			printf("%d",postFixResult[i].value);
		}
		else if(postFixResult[i].type!=OPERATION_PRIORITY_DUMMY){
			printf("%c",postFixResult[i].operation);
		}
	}
}

Data Pop(Data *stack, int *top){
	if(*top == -1){
		return Dummy;
	}
	else{
		(*top)--;
		return stack[(*top)+1];
	}
}

Data Top(Data *stack, int *top){
	if(*top == -1){
		return Dummy;
	}
	else return stack[*top];
}

void Push(Data *stack, int *top, Data k){
	(*top)++;
	stack[*top]=k;
}

void PostFix(Data *stack, Data *arr, int *top, int *size, Data k){
	if(k.type==NUMBER){
		arr[*size]=k;
		(*size)++;
	}
	else if(k.type==OPERATION_PRIORITY_1){
		if(k.operation=='('){
			Push(postFixStack, &postFixTop,k);
		}
		else if(k.operation=')'){
			while(Top(postFixStack, &postFixTop).type!=OPERATION_PRIORITY_1){
				arr[*size]=Pop(postFixStack, &postFixTop);
				(*size)++;
			}
			Pop(postFixStack, &postFixTop);
		}
	}
	else if(k.type==OPERATION_PRIORITY_2){
		while(Top(postFixStack, &postFixTop).type>=OPERATION_PRIORITY_2){
			arr[*size]=Pop(postFixStack, &postFixTop);
			(*size)++;
		}
		Push(postFixStack, &postFixTop,k);
	}
	else if(k.type==OPERATION_PRIORITY_3){
		while(Top(postFixStack, &postFixTop).type>=OPERATION_PRIORITY_3){
			arr[*size]=Pop(postFixStack, &postFixTop);
			(*size)++;
		}
		Push(postFixStack, &postFixTop,k);
	}
}

void PostFixFinish(Data *stack, Data *arr, int *top, int *size){
	while(Top(postFixStack, &postFixTop).type!=OPERATION_PRIORITY_DUMMY){
		arr[*size]=Pop(postFixStack, &postFixTop);
		(*size)++;
	}
	arr[*size]=Dummy;
}

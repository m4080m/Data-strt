#include<stdio.h>
#include<string.h>
#include<math.h>
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

typedef struct{
	long long int numerator;
	long long int denominator;
}Num;

Data PostFixPop(Data *stack, int *top);
Data PostFixTop(Data *stack, int *top);
void PostFixPush(Data *stack, int *top, Data k);
Num CalcPop(Data *stack, int *top);
Num CalcTop(Data *stack, int *top);
void CalcPush(Data *stack, int *top, Num k);
void PostFix(Data *stack, Data *arr, int *top, int *size, Data k);
void PostFixFinish(Data *stack, Data *arr, int *top, int *size);
void PostFixPrint(Data *arr, int *size);
Num Calculate(Data *arr, int *size);

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
		else if(str[i]=='('||str[i]==')'){
			newData.type=OPERATION_PRIORITY_1;
			newData.operation=str[i];
		}
		else if(str[i]=='+'||str[i]=='-'){
			newData.type=OPERATION_PRIORITY_2;
			newData.operation=str[i];
		}
		else if(str[i]=='*'||str[i]=='/'){
			newData.type=OPERATION_PRIORITY_3;
			newData.operation=str[i];
		}
		
		PostFix(postFixStack, postFixResult, &postFixTop, &postFixSize, newData);
	}
	PostFixFinish(postFixStack, postFixResult, &postFixTop, &postFixSize);
	PostFixPrint(postFixResult, &postFixSize);
	printf("\n");
	Num calculateRes=Calculate(postFixResult, &postFixSize);
	if(calculateRes.denominator%calculateRes.numerator==0){
		printf("%d",calculateRes.denominator/calculateRes.numerator);
	}
	else{
		printf("%lf",(double)calculateRes.denominator/calculateRes.numerator);
	}
}

int gcd(int a, int b){
    if(b==0){
        return a;
    }
	else{
        return gcd(b, a%b);
    }
}

Data PostFixPop(Data *stack, int *top){
	if(*top == -1){
		return Dummy;
	}
	else{
		(*top)--;
		return stack[(*top)+1];
	}
}

Data PostFixTop(Data *stack, int *top){
	if(*top == -1){
		return Dummy;
	}
	else return stack[*top];
}

void PostFixPush(Data *stack, int *top, Data k){
	(*top)++;
	stack[*top]=k;
}

Num CalcPop(Num *stack, int *top){
	(*top)--;
	return stack[(*top)+1];
}

Num CalcTop(Num *stack, int *top){
	return stack[*top];
}

void CalcPush(Num *stack, int *top, Num k){
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
			PostFixPush(postFixStack, &postFixTop,k);
		}
		else if(k.operation=')'){
			while(PostFixTop(postFixStack, &postFixTop).type!=OPERATION_PRIORITY_1){
				arr[*size]=PostFixPop(postFixStack, &postFixTop);
				(*size)++;
			}
			PostFixPop(postFixStack, &postFixTop);
		}
	}
	else if(k.type==OPERATION_PRIORITY_2){
		while(PostFixTop(postFixStack, &postFixTop).type>=OPERATION_PRIORITY_2){
			arr[*size]=PostFixPop(postFixStack, &postFixTop);
			(*size)++;
		}
		PostFixPush(postFixStack, &postFixTop,k);
	}
	else if(k.type==OPERATION_PRIORITY_3){
		while(PostFixTop(postFixStack, &postFixTop).type>=OPERATION_PRIORITY_3){
			arr[*size]=PostFixPop(postFixStack, &postFixTop);
			(*size)++;
		}
		PostFixPush(postFixStack, &postFixTop,k);
	}
}

void PostFixFinish(Data *stack, Data *arr, int *top, int *size){
	while(PostFixTop(postFixStack, &postFixTop).type!=OPERATION_PRIORITY_DUMMY){
		arr[*size]=PostFixPop(postFixStack, &postFixTop);
		(*size)++;
	}
	arr[*size]=Dummy;
}

void PostFixPrint(Data *arr, int *size){
	for(int i=0;i<(*size);i++){
		if(arr[i].type==NUMBER){
			printf("%d",arr[i].value);
		}
		else if(arr[i].type!=OPERATION_PRIORITY_DUMMY){
			printf("%c",arr[i].operation);
		}
	}
}

Num Calculate(Data *arr, int *size){
	Num calcStack[100];
	int calcStackTop=-1;
	for(int i=0;i<(*size);i++){
		if(arr[i].type==NUMBER){
			Num newNum;
			newNum.denominator=arr[i].value;
			newNum.numerator=1;
			CalcPush(calcStack, &calcStackTop, newNum);
		}
		else{
			Num num1, num2, numRes;
			int gcdRes;
			num2=CalcPop(calcStack, &calcStackTop);
			num1=CalcPop(calcStack, &calcStackTop);
			switch(arr[i].operation){
				case '+':
					gcdRes=gcd(num1.denominator, num2.denominator);
					numRes.denominator=(long long int)(num1.denominator*num2.numerator/gcdRes)+(long long int)(num2.denominator*num1.numerator/gcdRes);
					numRes.numerator=(long long int)(num1.numerator*num2.numerator/gcdRes);
					gcdRes=gcd((long long int)abs(numRes.denominator), numRes.numerator);
					numRes.denominator/=gcdRes;
					numRes.numerator/=gcdRes;
					break;
				case '-':
					gcdRes=gcd((long long int)abs(num1.denominator), (long long int)abs(num2.denominator));
					numRes.denominator=(long long int)(num1.denominator*num2.numerator/gcdRes)-(long long int)(num2.denominator*num1.numerator/gcdRes);
					numRes.numerator=(long long int)(num1.numerator*num2.numerator/gcdRes);
					gcdRes=gcd((long long int)abs(numRes.denominator), numRes.numerator);
					numRes.denominator/=gcdRes;
					numRes.numerator/=gcdRes;
					break;
				case '*':
					numRes.denominator=num1.denominator*num2.denominator;
					numRes.numerator=num1.numerator*num2.numerator;
					gcdRes=gcd((long long int)abs(numRes.denominator), numRes.numerator);
					numRes.denominator/=gcdRes;
					numRes.numerator/=gcdRes;
					break;
				case '/':
					numRes.denominator=num1.denominator*num2.numerator;
					numRes.numerator=num1.numerator*num2.denominator;
					if(numRes.numerator<0){
						numRes.numerator*=-1;
						numRes.denominator*=-1;
					}
					gcdRes=gcd((long long int)abs(numRes.denominator), numRes.numerator);
					numRes.denominator/=gcdRes;
					numRes.numerator/=gcdRes;
					break;
			}
			CalcPush(calcStack, &calcStackTop, numRes);
		}
	}
	return calcStack[0];
}

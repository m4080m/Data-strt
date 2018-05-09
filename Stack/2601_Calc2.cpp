#include<stdio.h>
#include<string.h>
#include<math.h>
#define NUMBER 0
#define OPERATION_PRIORITY_DUMMY -1
#define OPERATION_PRIORITY_1 1
#define OPERATION_PRIORITY_2 2
#define OPERATION_PRIORITY_3 3

typedef struct{
	long long int numerator;
	long long int denominator;
}Num;

typedef struct{
	int type;
	Num value;
	char operation;
}Data;

void Translate(char *string, Data *Target, int *length);
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
	char org[1000];
	Data str[1000];
	int len=0;
	scanf("%s",org);
	Translate(org,str,&len);
	for(int i=0;i<len;i++){
		PostFix(postFixStack, postFixResult, &postFixTop, &postFixSize, str[i]);
	}
	PostFixFinish(postFixStack, postFixResult, &postFixTop, &postFixSize);
	PostFixPrint(postFixResult, &postFixSize);
	printf("\n");
	Num calculateRes=Calculate(postFixResult, &postFixSize);
	if(calculateRes.numerator%calculateRes.denominator==0){
		printf("%d",calculateRes.numerator/calculateRes.denominator);
	}
	else{
		printf("%lf",(double)calculateRes.numerator/calculateRes.denominator);
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

void Translate(char *string, Data *Target, int *length){
	int len=strlen(string);
	int state=NUMBER;
	for(int i=0;i<len;i++){
		if(state==NUMBER){
			if(string[i]=='('){
				Target[*length].type=OPERATION_PRIORITY_1;
				Target[*length].operation=string[i];
				(*length)++;
				continue;
			}
			else{
				Num current;
				current.numerator=0;
				current.denominator=1;
				int neg=0;
				if(string[i]=='-'){
					neg=1;
					i++;
				}
				while('0'<=string[i]&&string[i]<='9'){
					current.numerator=current.numerator*10+(string[i]-'0');
					i++;
				}
				if(string[i]=='.'){
					i++;
					while('0'<=string[i]&&string[i]<='9'){
						current.numerator=current.numerator*10+(string[i]-'0');
						current.denominator*=10;
						i++;
					}
				}
				if(neg){
					current.numerator*=-1;
				}
				i--;
				state=1;
				Target[*length].type=NUMBER;
				Target[*length].value=current;
				(*length)++;
				continue;
			}
		}
		else{
			if(string[i]==')'){
				Target[*length].type=OPERATION_PRIORITY_1;
				Target[*length].operation=string[i];
			}
			else if(string[i]=='+'||string[i]=='-'){
				Target[*length].type=OPERATION_PRIORITY_2;
				Target[*length].operation=string[i];
				state=0;
			}
			else if(string[i]=='*'||string[i]=='/'){
				Target[*length].type=OPERATION_PRIORITY_3;
				Target[*length].operation=string[i];
				state=0;
			}
			(*length)++;
			continue;
		}
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
			if(arr[i].value.numerator%arr[i].value.denominator==0){
				printf("%d",arr[i].value.numerator/arr[i].value.denominator);
			}
			else{
				printf("%lf",(double)arr[i].value.numerator/arr[i].value.denominator);
			}
		}
		else if(arr[i].type!=OPERATION_PRIORITY_DUMMY){
			printf("%c",arr[i].operation);
		}
	}
}

Num Calculate(Data *arr, int *size){
	Num calcStack[1000];
	int calcStackTop=-1;
	for(int i=0;i<(*size);i++){
		if(arr[i].type==NUMBER){
			Num newNum=arr[i].value;
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
					numRes.numerator=(long long int)(num1.denominator*num2.numerator/gcdRes)+(long long int)(num2.denominator*num1.numerator/gcdRes);
					numRes.denominator=(long long int)(num1.denominator*num2.denominator/gcdRes);
					gcdRes=gcd((long long int)abs(numRes.denominator), numRes.numerator);
					numRes.denominator/=gcdRes;
					numRes.numerator/=gcdRes;
					break;
				case '-':
					gcdRes=gcd(num1.denominator, num2.denominator);
					numRes.numerator=(long long int)(num2.denominator*num1.numerator/gcdRes)-(long long int)(num1.denominator*num2.numerator/gcdRes);
					numRes.denominator=(long long int)(num1.denominator*num2.denominator/gcdRes);
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

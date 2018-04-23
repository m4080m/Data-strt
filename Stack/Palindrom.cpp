#include<stdio.h>
#include<string.h>
char st1[30], st2[30],tp[30];
int top1=-1, top2=-1, top_p=-1;
char arr[30];

char Pop(char *stack, int *top){
	if(*top == -1){
		return 0;
	}
	else{
		(*top)--;
		return stack[(*top)+1];
	}
}
char Top(char *stack, int *top){
	if(*top == -1){
		return 0;
	}
	else return stack[*top];
}
int Push(char *stack, int *top, char k){
	(*top)++;
	stack[*top]=k;
}
int main(){
	fgets(arr,sizeof(arr),stdin);
	int len=strlen(arr);
	for(int i=0;i<len;i++){
		if(arr[i]!=' '){
			Push(st1, &top1, arr[i]);
			Push(tp, &top_p, arr[i]);
		}
	}
	for(int i=0;i<=top1;i++){
		Push(st2, &top2, Pop(tp,&top_p));
	}
	int res=1;
	Pop(st1,&top1);
	for(int i=0;i<=top1;i++){
		if(Pop(st1,&top1)!=Pop(st2,&top2)){
			res=0;
			break;
		}
	}
	if(res)printf("Yes");
	else printf("No");
}

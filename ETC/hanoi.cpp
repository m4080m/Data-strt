#include<stdio.h>
#include<stack>
using namespace std;
stack<int> st[3];

int hanoi(int size, int here, int to, int x){
	if(size==1){
		printf("%d %c->%c\n",size,'A'+here,'A'+to);
		st[to].push(st[here].top());
		st[here].pop();
	}
	else{
		hanoi(size-1,here,x,to);
		hanoi(1,here,to,x);
		hanoi(size-1,x,to,here);
	}
}

int main(){
	int n;
	scanf("%d",&n);
	for(int i=n;i>0;i--) st[0].push(i);
	hanoi(n,0,2,1);
}

#include<stdio.h>
int queue[1000], top=0, bottom=0;
void Enqueue(int k){
	queue[top]=k;
	top++;
}
int Dequeue(){
	bottom++;
	return queue[bottom-1];
}
int Top(){
	return queue[bottom];
}
int main(){
	int n;
	scanf("%d",&n);
	Enqueue(0);
	Enqueue(1);
	int result;
	for(int i=2;i<=n;i++){
		result=Dequeue()+Top();
		Enqueue(result);
	}
	printf("%d",result);
}

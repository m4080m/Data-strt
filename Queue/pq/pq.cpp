#include<stdio.h>
int pq[100], size=0;
int pop(){
	int data = pq[1];
	pq[1] = pq[size];
	size--;
	int current = 1;
	int temp;
	while(1){
		int next;
		if(current*2>size){
			break;
		}
		else if(current*2+1>size){
			next = current*2;
		}
		else next = pq[current*2]<pq[current*2+1]?current*2:current*2+1;
		if(pq[current]>pq[next]){
			temp = pq[current];
			pq[current] = pq[next];
			pq[next] = temp;
			current = next;
		}
		else{
			break;
		}
	}
	for(int i=1;i<=size;i++){
		printf("%d ",pq[i]);
	}
	printf("pop: %d\n",data);
	return data;
}
void push(int data){
	size++;
	pq[size]=data;
	int current = size;
	int temp;
	while(current>1){
		if(pq[current]<pq[current/2]){
			temp = pq[current];
			pq[current] = pq[current/2];
			pq[current/2] = temp;
			current = current/2;
		}
		else{
			break;
		}
	}
	for(int i=1;i<=size;i++){
		printf("%d ",pq[i]);
	}
	printf("\n");
}
int main(){
	for(int i=5;i>=-5;i--){
		push(i);
	}
	while(size>0){
		pop();
	}
}

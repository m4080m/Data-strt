#include <stdio.h>
#include "CQueue.h"

void QInit(Que * pque){
	pque->front=0;
	pque->rear=0;
}

int QEmpty(Que *pque){
	if(pque->front==pque->rear){
		return TRUE;
	}
	else{
		return FALSE;
	}
}

void Enqueue(Que * pque, Data data){
	if(QNextIdx(pque->rear)==pque->front){
		puts("������ �Ұ����մϴ�.");
		return; 
	}
	
	pque->rear=QNextIdx(pque->rear);
	pque->arr[pque->rear]=data;
}

Data Dequeue(Que * pque){
	if(QEmpty(pque)){
		puts("�ҷ����Ⱑ �Ұ����մϴ�.");
		return -1;
	}
	pque->front=QNextIdx(pque->front);
	return pque->arr[pque->front]; 
}

int QNextIdx(int pos){
	if(pos==QUEUE_LEN-1){
		return 0;
	}
	else{
		return pos+1;
	}
}

Data QPeak(Que * pque){
	if(QEmpty(pque)){
		puts("�ҷ����Ⱑ �Ұ����մϴ�.");
		return -1;
	}
	return pque->arr[pque->front];
}

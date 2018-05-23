#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"CQueue.h"

#define ORDER_TERM 15

#define CHEESE 0
#define BULGOGI 1
#define DOUBLE 2

#define TERM_CHEESE 12
#define TERM_BULGOGI 15
#define TERM_DOUBLE 24

#define TEST_NUM 1000000
#define SIM_TIME 3600

int result[61];

void Simulation(){
	int progress=0;
	int queueSize=0, maxQueueSize=0;
	int sec;
	Que que;
	QInit(&que);
	
	for(sec=0;sec<SIM_TIME;sec++){
		if(sec % ORDER_TERM == 0){
			int order=rand()%3;
			switch(order){
				case CHEESE:
					Enqueue(&que, TERM_CHEESE);
					break;
				case BULGOGI:
					Enqueue(&que, TERM_BULGOGI);
					break;
				case DOUBLE:
					Enqueue(&que, TERM_DOUBLE);
					break;
			}
			queueSize++;
			if(maxQueueSize<queueSize){
				maxQueueSize=queueSize;
			}
		}
		if(!QEmpty(&que)){
			progress++;
			if(progress==QPeak(&que)){
				progress=0;
				Dequeue(&que);
				queueSize--;
			}
		}
	}
	int i;
	for(i=0;i<=maxQueueSize;i++){
		result[i]++;
	}
}

int main(){
	srand(time(NULL));
	int i;
	for(i=0;i<TEST_NUM;i++){
		Simulation();
	}
	for(i=1;i<61;i++){
		printf("Size over %2d: %.05lf%%\n",i,(double)result[i]/TEST_NUM*100);
	}
}

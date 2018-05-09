#ifndef __ARRAY_LIST_H__
#define __ARRAY_LIST_H__

#define TRUE	1
#define FALSE	0

/*** ArrayList¿« ¡§¿« ****/
#define QUEUE_LEN	100
typedef int Data;

typedef struct
{
	Data arr[QUEUE_LEN];
	int rear;
	int front;
} CQueue;

typedef CQueue Que;

void QInit(Que * pque);
void Enqueue(Que * pque, Data data);
Data Dequeue(Que * pque);

int QNextIdx(int pos);

int QEmpty(Que *pque);
Data Qpeak(Que * pque);

#endif

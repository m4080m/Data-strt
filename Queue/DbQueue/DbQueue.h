//#ifndef __D_QUEUE_H__
#define __D_QUEUE_H__

#define TRUE	1
#define FALSE	0

typedef int LData;

typedef struct _node{
	LData data;
	struct _node *next;
	struct _node *prev;
}Node;

typedef struct{
	Node *head;
	Node *tail;
	Node *cur;
	int numOfData;
	int (*comp)(LData d1, LData d2);
}List;

void ListInit(List *plist);
void LInsert(List *plist, LData data);

int LFirst(List *plist, LData *pdata);
int LNext(List *plist, LData *pdata);

LData LDelete(List *plist);
void LClear(List *plist);

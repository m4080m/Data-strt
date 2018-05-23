//#ifndef __C_LINKED_LIST_H__
#define __C_LINKED_LIST_QUEUE_H__

#define TRUE	1
#define FALSE	0

typedef int LData;

typedef struct _node{
	LData data;
	struct _node *next;
}Node;

typedef struct{
	Node *tail;
	Node *cur;
	Node *before;
	int numOfData;
}List;

void ListInit(List *plist);
void LInsert(List *plist, LData data);

int LFirst(List *plist, LData *pdata);
int LNext(List *plist, LData *pdata);

LData LDelete(List *plist);

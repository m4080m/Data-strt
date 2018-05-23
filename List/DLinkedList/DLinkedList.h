//#ifndef __D_LINKED_LIST_H__
#define __D_LINKED_LIST_H__

#define TRUE	1
#define FALSE	0

typedef int LData;

typedef struct _node{
	LData data;
	struct _node *next;
}Node;

typedef struct{
	Node *head;
	Node *tail;
	Node *cur;
	Node *before;
	int numOfData;
	int (*comp)(LData d1, LData d2);
}List;

void ListInit(List *plist);
void LInsert(List *plist, LData data);

int LFirst(List *plist, LData *pdata);
int LNext(List *plist, LData *pdata);

LData LDelete(List *plist);
void LClear(List *plist);

void SetSortRule(List *plist, int (*comp)(LData d1, LData d2));
void SInsert(List *plist, LData data);

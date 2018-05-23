#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree.h"

BTreeNode * MakeBTreeNode(void){
	BTreeNode * newNode = (BTreeNode *)malloc(sizeof(BTreeNode));
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}
BTData GetData(BTreeNode * bt){
	return bt->data;
}

void SetData(BTreeNode * bt, BTData data){
	bt->data = data;
	return;
}

BTreeNode * GetLeftSubTree(BTreeNode * bt){
	return bt->left;
}
BTreeNode * GetRightSubTree(BTreeNode * bt){
	return bt->right;
}

void MakeLeftSubTree(BTreeNode * main, BTreeNode * sub){
	main->left = sub;
	return;
}
void MakeRightSubTree(BTreeNode * main, BTreeNode * sub){
	main->right = sub;
}

typedef void VisitFuncPtr(BTData data);

void PreorderTraverse(BTreeNode * bt, VisitFuncPtr action){
	action(bt->data);
	if(GetLeftSubTree(bt) != NULL){
		PreorderTraverse(GetLeftSubTree(bt), action);
	}
	if(GetRightSubTree(bt) != NULL){
		PreorderTraverse(GetRightSubTree(bt), action);
	}
}
void InorderTraverse(BTreeNode * bt, VisitFuncPtr action){
	if(GetLeftSubTree(bt) != NULL){
		InorderTraverse(GetLeftSubTree(bt), action);
	}
	action(bt->data);
	if(GetRightSubTree(bt) != NULL){
		InorderTraverse(GetRightSubTree(bt), action);
	}
}
void PostorderTraverse(BTreeNode * bt, VisitFuncPtr action){
	if(GetLeftSubTree(bt) != NULL){
		PostorderTraverse(GetLeftSubTree(bt), action);
	}
	if(GetRightSubTree(bt) != NULL){
		PostorderTraverse(GetRightSubTree(bt), action);
	}
	action(bt->data);
}

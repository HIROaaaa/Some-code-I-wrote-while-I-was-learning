#define _CRT_SECURE_NO_WARNINGS
#include"SList.h"
int main()
{
	SLTNode* plist=NULL;
	SLTPushBack(&plist, 1);
	SLTPushBack(&plist, 2);
	SLTPushBack(&plist, 5);
	SLTPushBack(&plist, 4);
	SLTPushBack(&plist, 7);
	SLTPushBack(&plist, 3);
	SLTPushBack(&plist, 4);
	SLTPushBack(&plist, 7);
	//SLTPushBack(&plist, 4);
	//SLTPushBack(&plist, 6);
	//SLTPushBack(&plist, 15);
	//SLTPushBack(&plist, 3);
	//SLTPushBack(&plist, 7);
	//SLTPrint(&plist);
	//SLTPushFront(&plist, 10);
	//SLTPushFront(&plist, 20);
	//SLTPrint(&plist);
	//SLTPopBack(&plist);
	//SLTPrint(&plist);
	//SLTPopFront(&plist);
	//SLTPrint(&plist);
	//SLTNode* ret=SLTFind(plist, 10);
	//SLTInsert(&plist, ret, 11);
	//SLTPrint(&plist);
	//SLTInsertAfter(ret, 67); 
	//SLTPrint(&plist);
	//SLTErase(&plist, ret);
	//SLTPrint(&plist);
	//SLTEraseAfter(ret);
	//SLTPrint(&plist);
	//SListDesTroy(&plist); 
	//SLTPrint(&plist);
	//plist = reverseList(plist);
	//SLTPrint(&plist);
	//SLTNode* ret2 = middleNode(plist);
	//printf("%d", ret2->data);
	//SLTNode* plist2 = NULL;
	//SLTPushBack(&plist2, 3);
	//SLTPushBack(&plist2, 4);
	//SLTPushBack(&plist2, 5);
	//SLTPushBack(&plist2, 8);
	//SLTPushBack(&plist2, 9);
	//SLTPushBack(&plist2, 10);
	//SLTPushBack(&plist2, 11);
	//SLTPushBack(&plist2, 15);
	//SLTNode* plist3 = mergeTowLists(plist, plist2);
	//SLTPrint(&plist3);
	SLTPrint(&plist);
	SLTNode* tail =partition(plist,4);
	SLTPrint(&tail);
}

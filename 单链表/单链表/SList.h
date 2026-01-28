#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef int SLTDataType;
typedef struct SListNode
{
	SLTDataType data;
	struct SListNode* next;
}SLTNode;
void SLTPrint(SLTNode** phead);
//头部插⼊删除/尾部插⼊删除
void SLTPushBack(SLTNode * *pphead, SLTDataType x);
void SLTPushFront(SLTNode * *pphead, SLTDataType x);
void SLTPopBack(SLTNode * *pphead);
void SLTPopFront(SLTNode * *pphead);
//
////查找
SLTNode * SLTFind(SLTNode * phead, SLTDataType x);
////在指定位置之前插⼊数据
void SLTInsert(SLTNode * *pphead, SLTNode * pos, SLTDataType x);
////删除pos节点
void SLTErase(SLTNode** pphead, SLTNode* pos);
//在指定位置之后插⼊数据
void SLTInsertAfter(SLTNode* pos, SLTDataType x);
////删除pos之后的节点
void SLTEraseAfter(SLTNode* pos);
////销毁链表
void SListDesTroy(SLTNode** pphead);
SLTNode* reverseList(SLTNode* pphead);
SLTNode* middleNode(SLTNode* phead);
SLTNode* mergeTowLists(SLTNode* list1, SLTNode* list2);
SLTNode* creatCircle(SLTNode* list);
int ysf(SLTNode* list,int m);
SLTNode* partition(SLTNode* phead, SLTDataType x);

#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef int SLDataType;
typedef struct ListNode
{
	SLDataType data;
	struct ListNode* next;
	struct ListNode* prev;
}LTNode;
LTNode* LTInit();
void LTPushBack(LTNode* phead, SLDataType x);
void LTPushFront(LTNode* phead, SLDataType x);
void LTPrint(LTNode* phead);
void LTPopBack(LTNode* phead);
void LTPopFront(LTNode* phead);
LTNode* LTFind(LTNode* phead,SLDataType x);
void LTInsert(LTNode* phead, SLDataType x);
void LTErase(LTNode* pos);
void LTDesTory(LTNode* phead);
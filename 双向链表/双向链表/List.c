#define _CRT_SECURE_NO_WARNINGS
#include"List.h"
LTNode* LTBuyNode(SLDataType x)
{
	LTNode* newnode = (LTNode*)malloc(sizeof(LTNode));
	if (newnode == NULL)
	{
		perror("malloc fail");
		exit(1);
	}
	newnode->data = x;
	newnode->next = newnode->prev = newnode;
	return newnode;
}
LTNode* LTInit()
{
	LTNode* phead = LTBuyNode(-1);
	return phead;
}
void LTPushBack(LTNode* phead,SLDataType x)
{
	assert(phead);
	LTNode* newnode = LTBuyNode(x);
	newnode->next = phead;
	newnode->prev = phead->prev;
	phead->prev->next = newnode;
	phead->prev = newnode;
}
void LTPushFront(LTNode* phead, SLDataType x)
{
	assert(phead);
	LTNode* newnode = LTBuyNode(x);
	newnode->next = phead->next;
	newnode->prev = phead;
	phead->next->prev = newnode;
	phead->next = newnode;
}
void LTPrint(LTNode* phead)
{
	LTNode* pcur = phead->next;
	while (pcur != phead)
	{
		printf("%d->", pcur->data);
		pcur = pcur->next;
	}
	printf("\n");
}
void LTPopBack(LTNode* phead)
{
	assert(phead&& phead->next != phead);
	LTNode* del=phead->prev;
	phead->prev = del->prev;
	del->prev->next = phead;
	free(del); 
	del = NULL;
}
void LTPopFront(LTNode* phead)
{
	assert(phead && phead->next != phead);
	LTNode* del = phead->next;
	phead->next = del->next;
	del->next->prev = phead;
	free(del);
	del = NULL;
}
LTNode* LTFind(LTNode* phead, SLDataType x)
{
	assert(phead);
	LTNode* pcur = phead->next;
	while (pcur != phead)
	{
		if (pcur->data == x)
		{
			return pcur;
		}
		pcur = pcur->next;
	}
	printf("Î´ÕÒµ½");
	return NULL;
}
void LTInsert(LTNode* pos, SLDataType x)
{
	assert(pos);
	LTNode* newnode = LTBuyNode(x);
	newnode->next = pos->next;
	newnode->prev = pos;
	pos->next->prev = newnode;
	pos->next = newnode;
}
void LTErase(LTNode* pos)
{
	assert(pos);
	pos->next->prev = pos->prev;
	pos->prev->next = pos->next;
	free(pos);
	pos = NULL;
}
void LTDesTory(LTNode* phead)
{
	assert(phead);
	LTNode* pcur = phead->next;
	LTNode* next = pcur->next;
	while (pcur != phead)
	{
		free(pcur);
		pcur = next;
		next = next->next;
	}
	free(phead);
	phead = NULL;
}

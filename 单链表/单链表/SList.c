#define _CRT_SECURE_NO_WARNINGS
#include"SList.h"
void SLTPrint(SLTNode** pphead)
{
	SLTNode* pcur = *pphead;
	while (pcur)
	{
		printf("%d->", pcur->data);
		pcur = pcur->next;
	}
	printf("NULL\n");
}
SLTNode* SLTBuyNode(SLTDataType x)
{
	SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));
	if (newnode == NULL)
	{
		perror("malloc fail!");
		exit(1);
	}
	newnode->data = x;
	newnode->next = NULL;
	return newnode;
}
void SLTPushBack(SLTNode** pphead, SLTDataType x)
{
	assert(pphead);
	SLTNode* newnode = SLTBuyNode(x);
	if (*pphead == NULL)
	{
		*pphead = newnode;
	}
	else
	{
		//ÕÒÎ²
		SLTNode* ptial = *pphead;
		while (ptial->next != NULL)
		{
			ptial = ptial->next;
		}
		ptial->next = newnode;
	}
}
void SLTPushFront(SLTNode** pphead, SLTDataType x)
{
	assert(pphead);
	SLTNode* newnode = SLTBuyNode(x);
	newnode->next = *pphead;
	*pphead = newnode;
}
void SLTPopBack(SLTNode** pphead)
{
	assert(pphead&&*pphead);
	if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	else
	{
		SLTNode* ptail = *pphead;
		SLTNode* prev = *pphead;
		while (ptail->next)
		{
			prev = ptail;
			ptail = ptail->next;
		}
		free(ptail);
		prev->next = NULL;
	}
}
void SLTPopFront(SLTNode** pphead)
{
	assert(pphead&&*pphead);
	SLTNode* next = (*pphead)->next;
	free(*pphead);
	(*pphead) = next;

}
SLTNode* SLTFind(SLTNode* phead, SLTDataType x)
{
	SLTNode* pcur = phead;
	while (pcur)
	{
		if (pcur->data == x)
		{
			return pcur;
		}
		pcur = pcur->next;
	}
	return NULL;
}
void SLTInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x)
{
	assert(pphead && *pphead);
	assert(pos);
	SLTNode* newnode = SLTBuyNode(x);
	SLTNode* prev = *pphead;
	if (pos == *pphead)
	{
		SLTPushFront(pphead, x);
	}
	else
	{
		while (prev->next != pos)
		{
			prev = prev->next;
		}

		prev->next = newnode;
		newnode->next = pos;
	}
}
void SLTInsertAfter(SLTNode* pos, SLTDataType x)
{
	assert(pos);
	SLTNode* newnode = SLTBuyNode(x);
	newnode->next = pos->next;
	pos->next = newnode;
}
void SLTErase(SLTNode** pphead, SLTNode* pos)
{
	assert(pphead && *pphead);
	assert(pos);
	if (pos == *pphead)
	{
		SLTPopFront(pphead);
	}
	else
	{
		SLTNode* prev = *pphead;
		while (prev->next != pos)
		{
			prev = prev->next;
		}
		prev->next = pos->next;
		free(pos);
		pos = NULL;
	}
}
void SLTEraseAfter(SLTNode* pos)
{
	assert(pos&&pos->next);
	SLTNode* del = pos->next;
	pos->next = pos->next->next;
	free(del);
	del = NULL;
}
void SListDesTroy(SLTNode** pphead)
{
	assert(pphead&&*pphead);
	SLTNode* pcur = *pphead;
	while (pcur)
	{
		SLTNode* next = pcur->next;
		free(pcur);
		pcur = next;
	}
	*pphead = NULL;
}
SLTNode* reverseList(SLTNode* phead)
{
	if (phead == NULL)
	{
		return phead;
	}
	SLTNode* n1 = NULL;
	SLTNode* n2 = phead;
	SLTNode* n3 = n2->next;
	while (n2)
	{
		n2->next = n1;
		n1 = n2;
		n2 = n3;
		if(n3)
		n3 = n3->next;
	}
	return n1;
}
SLTNode* middleNode(SLTNode* phead)
{
	assert(phead);
	SLTNode* slow = phead;
	SLTNode* fast = phead;
	while (fast&&fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;
}
SLTNode* mergeTowLists(SLTNode* list1, SLTNode* list2)
{
	if (list1 == NULL)
	{
		return list2;
	}
	else
	{
		return list1;
	}
	SLTNode* l1 = list1;
	SLTNode* l2 = list2;
	SLTNode* newhead=NULL;
	SLTNode* newtail=NULL;
	newhead = newtail=(SLTNode*)malloc(sizeof(SLTNode));
	while (l1 && l2)
	{
		if (l1->data < l2->data)
		{
			newtail->next = l1;
			newtail = newtail->next;
			l1 = l1->next;
		}
		else
		{
			newtail->next = l2;
			newtail = newtail->next;
			l2 = l2->next;
		}
	}
	if (l1 == NULL)
	{
		newtail->next = l2;
	}
	else
	{
		newtail->next = l1;
	}
	SLTNode* ret = newhead->next;
	free(newhead);
	newhead = NULL;
	return ret;
}
SLTNode* creatCircle(SLTNode* list)
{
	SLTNode* tail = list;
	while (tail->next)
	{
		tail = tail->next;
	}
	tail->next = list;
	return tail;
}
int ysf(SLTNode* tail,int m)
{
	SLTNode* prev = tail;
	SLTNode* pcur = tail->next;
	int count = 1;
	while (pcur->next!=pcur)
	{
		if (count == m)
		{
			prev->next = pcur->next;
			free(pcur);
			pcur = prev->next;
			count = 1;
		}
		else
		{
			prev = pcur;
			pcur = pcur->next;
			count++;
		}
	}
	return pcur->data;
}
SLTNode* partition(SLTNode* phead, SLTDataType x)
{
	if (phead == NULL)
		return phead;

	SLTNode* lesshead, *lesstial;
	SLTNode* greaterhead, *greatertail;
	lesshead = lesstial = (SLTNode*)malloc(sizeof(SLTNode));
	greaterhead = greatertail = (SLTNode*)malloc(sizeof(SLTNode));
	SLTNode* pcur = phead;
	while (pcur)
	{
		if (pcur->data < x)
		{
			lesstial->next = pcur;
			lesstial = lesstial->next;
		}
		else {
			greatertail->next = pcur;
			greatertail = greatertail->next;
		}
		pcur = pcur->next;
	}
	greatertail->next = NULL;
	lesstial->next = greaterhead->next;
	SLTNode* ret = lesshead->next;
	free(lesshead);
	free(greaterhead);
	lesshead = greaterhead = NULL;
	return ret;
}
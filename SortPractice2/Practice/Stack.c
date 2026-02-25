#define _CRT_SECURE_NO_WARNINGS
#include "Stack.h"
//初始化和销毁
void STInit(ST* pst)
{
	assert(pst);
	pst->arr = NULL;
	pst->capacity = 0;
	pst->top = 0;
}
void STDestory(ST* pst)
{
	assert(pst);
	free(pst->arr);
	pst->arr = NULL;
	pst->capacity = 0;
	pst->top = 0;
}
//出栈和入栈
void STPush(ST* pst, STDataTpye x)
{
	assert(pst);
	//扩容
	if (pst->capacity == pst->top)
	{
		int newcapacity = pst->capacity == 0 ? 4 : pst->capacity * 2;
		STDataTpye* tmp = (STDataTpye*)realloc(pst->arr, newcapacity * sizeof(STDataTpye));
		if(tmp==NULL)
		{
			perror("relloc fail");
			return;
		}
		pst->arr = tmp;
		pst->capacity = newcapacity;
	}
	pst->arr[pst->top] = x;
	pst->top++;
}
void STPop(ST* pst)
{
	assert(pst);
	pst->top--;
}
//取栈顶数据
STDataTpye STTop(ST* pst)
{
	assert(pst);
	return pst->arr[pst->top - 1];
}
//判空
bool STEmpty(ST* pst)
{
	assert(pst);
	return pst->top == 0;
}
//取数据个数
//判断括号是否匹配
bool isValid(char* s)
{
	ST st;
	STInit(&st);
	while (*s)
	{
		if (*s == '{' || *s == '[' || *s == '(')
		{
			STPush(&st, *s);
		}
		else
		{
			if (STEmpty(&st))
			{
				STDestory(&st);
				return false;
			}
			char top = STTop(&st);
			STPop(&st);
			if (top == '[' && *s != ']'
				|| top == '{' && *s != '}'
				|| top == '(' && *s != ')')
			{
				STDestory(&st);
				return false;
			}
		}
		s++;
	}
	bool ret = STEmpty(&st);
	STDestory(&st);
	return ret;
}

typedef struct {
	ST pushst;
	ST popst;
} MyQueue;


//用栈实现队列
MyQueue* myQueueCreate() {
	MyQueue* obj = (MyQueue*)malloc(sizeof(MyQueue));
	STInit(&obj->pushst);
	STInit(&obj->popst);
	return obj;
}

void myQueuePush(MyQueue* obj, int x) {
	STPush(&obj->pushst, x);
}

int myQueuePeek(MyQueue* obj) {
	if (STEmpty(&obj->popst))
	{
		while (!STEmpty(&obj->pushst))
		{
			STDataTpye tmp = STTop(&obj->pushst);
			STPush(&obj->popst, tmp);
			STPop(&obj->pushst);
		}
	}
	return STTop(&obj->popst);
}

int myQueuePop(MyQueue* obj) {
	STDataTpye front = myQueuePeek(obj);
	STPop(&obj->popst);
	return front;
}



bool myQueueEmpty(MyQueue* obj) {
	return STEmpty(&obj->pushst) && STEmpty(&obj->popst);
}

void myQueueFree(MyQueue* obj) {
	STDestory(&obj->pushst);
	STDestory(&obj->popst);
	free(obj);
}

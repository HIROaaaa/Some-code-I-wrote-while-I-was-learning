#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>
typedef int STDataTpye;
typedef struct Stack
{
	STDataTpye* arr;
	int top;
	int capacity;
}ST;
//初始化和销毁
void STInit(ST* pst);
void STDestory(ST* pst);
//出栈和入栈
void STPush(ST* pst,STDataTpye x);
void STPop(ST* pst);
//取栈顶数据
STDataTpye STTop(ST* pst);
//判空
bool STEmpty(ST* spt);
//取数据个数 
int STSize(ST* pst);
bool isValid(char* s);



//用栈实现队列
//MyQueue* myQueueCreate();
//void myQueuePush(MyQueue* obj, int x);
//int myQueuePeek(MyQueue* obj);
//int myQueuePop(MyQueue* obj);
//bool myQueueEmpty(MyQueue* obj);
//void myQueueFree(MyQueue* obj);


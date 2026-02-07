#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct BinaryTreeNode* QDataType;
typedef struct QueueNode
{
	struct QueueNode* next;
	QDataType val;
}QNode;
typedef struct Queue
{
	QNode* phead;
	QNode* ptail;
	int size;
}Queue;

//初始化
void QueueInit(Queue* pq);
//销毁
void QueueDestory(Queue* pq);
//尾插
void QueuePush(Queue* pq,QDataType x);
//队头删除
void QueuePop(Queue* pq);
//取队列数量
int QueueSize(Queue* pq);
//取队头
QDataType QueueFront(Queue* pq);
//取队尾
QDataType QueueBack(Queue* pq);
//判空
bool QueueEmpty(Queue* pq);

//用队列实现栈

typedef struct {
	Queue q1;
	Queue q2;
} MyStack;
MyStack* myStackCreate();
void myStackPush(MyStack* obj, int x);
int myStackPop(MyStack* obj);
int myStackTop(MyStack* obj);
bool myStackEmpty(MyStack* obj);
void myStackFree(MyStack* obj);
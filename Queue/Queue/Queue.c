#define _CRT_SECURE_NO_WARNINGS
#include"Queue.h"
//初始化
void QueueInit(Queue* pq)
{
	assert(pq);
	pq->phead = NULL;
	pq->ptail = NULL;
	pq->size = 0;
}
//销毁
void QueueDestory(Queue* pq)
{
	assert(pq);
	QNode* cur = pq->phead;
	while (cur)
	{
		QNode* next = cur->next;
		free(cur);
		cur = next;
	}
	pq->phead = pq->ptail = NULL;
	pq->size = 0;
}
//尾插
void QueuePush(Queue* pq, QDataType x)
{
	assert(pq);
	QNode* newnode = (QNode*)malloc(sizeof(QNode));
	if (newnode == NULL)
	{
		perror("malloc fail");
		return;
	}
	newnode->next = NULL;
	newnode->val = x;
	if (pq->ptail == NULL)
	{
		pq->phead = pq->ptail = newnode;
	}
	else
	{
		pq->ptail->next = newnode;
		pq->ptail = newnode;
	}
	pq->size++;
}
//队头删除
void QueuePop(Queue* pq)
{
	assert(pq);
	assert(pq->size != 0);
	if (pq->phead == pq->ptail)
	{
		free(pq->phead);
		pq->phead = pq->ptail = NULL;
	}
	else
	{
		QNode* next = pq->phead->next;
		free(pq->phead);
		pq->phead = next;
	}

	pq->size--;
}
//取队列数量
int QueueSize(Queue* pq)
{
	assert(pq);
	return pq->size;
}
//取队头
QDataType QueueFront(Queue* pq)
{
	assert(pq);
	assert(pq->phead);
	return pq->phead->val;
}
//取队尾
QDataType QueueBack(Queue* pq)
{
	assert(pq);
	assert(pq->ptail);
	return pq->ptail->val;
}
bool QueueEmpty(Queue* pq)
{
	assert(pq);
	return pq->size == 0;
}



//用队列实现栈



MyStack* myStackCreate() {
	MyStack* pst = (MyStack*)malloc(sizeof(MyStack));
	QueueInit(&pst->q1);
	QueueInit(&pst->q2);
	return pst;
}

void myStackPush(MyStack* obj, int x) {
	assert(obj);
	if (!QueueEmpty(&obj->q1))
	{
		QueuePush(&obj->q1, x);
	}
	else
	{
		QueuePush(&obj->q2, x);
	}
}

int myStackPop(MyStack* obj) {
	Queue* empty = &obj->q1;
	Queue* noempty = &obj->q2;
	if (!QueueEmpty(empty))
	{
		empty = &obj->q2;
		noempty = &obj->q1;
	}
	while (QueueSize(noempty) > 1)
	{
		QueuePush(empty, QueueFront(noempty));
		QueuePop(noempty);
	}
	QDataType top = QueueFront(noempty);
	QueuePop(noempty);
	return top;
}

int myStackTop(MyStack* obj) {
	if (!QueueEmpty(&obj->q1))
	{
		return QueueBack(&obj->q1);
	}
	else {
		return QueueBack(&obj->q2);
	}
}

bool myStackEmpty(MyStack* obj) {

	return QueueEmpty(&obj->q1) && QueueEmpty(&obj->q2);
}

void myStackFree(MyStack* obj) {
	QueueDestory(&obj->q1);
	QueueDestory(&obj->q2);
	free(obj);
}
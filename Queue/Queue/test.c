#define _CRT_SECURE_NO_WARNINGS
#include"Queue.h"
int main()
{
	Queue q;
	QueueInit(&q);
	QueuePush(&q, 1);
	QueuePush(&q, 3);
	QueuePush(&q, 10);
	QueuePush(&q, 245);
	QueuePush(&q, 2);
	QueuePush(&q, 5);
	while (!QueueEmpty(&q))
	{
		printf("%d\n", QueueFront(&q));
		QueuePop(&q);
	}
	return 0;
}
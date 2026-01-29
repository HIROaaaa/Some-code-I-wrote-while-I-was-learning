#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
typedef struct {
    int* a;
    int head;
    int tail;
    int k;

} MyCircularQueue;


MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue* obj = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
    obj->a = malloc(sizeof(int) * (k + 1));
    obj->head = obj->tail = 0;
    obj->k = k;
    return obj;
}
bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    return obj->tail == obj->head;
}
bool myCircularQueueIsFull(MyCircularQueue* obj) {
    return (obj->tail + 1) % (obj->k + 1) == obj->head;
}
bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    if (myCircularQueueIsFull(obj))
    {
        return false;
    }
    obj->a[obj->tail] = value;
    obj->tail++;
    obj->tail %= (obj->k + 1);
    return true;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj))
    {
        return false;
    }
    obj->a[obj->head] = 0;
    obj->head = (obj->head + 1) % (obj->k + 1);
    return true;
}

int myCircularQueueFront(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj))
    {
        return -1;
    }
    else
    {
        return obj->a[obj->head];
    }
}

int myCircularQueueRear(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj))
        return -1;
    else
    {
        return obj->a[(obj->tail - 1 + obj->k + 1) % (obj->k + 1)];
    }
}

void myCircularQueueFree(MyCircularQueue* obj) {
    free(obj->a);
    free(obj);
}
int main()
{
    MyCircularQueue* cq = myCircularQueueCreate(4);
    myCircularQueueEnQueue(cq, 1);
    myCircularQueueEnQueue(cq, 4);
    myCircularQueueEnQueue(cq, 3);
    myCircularQueueEnQueue(cq, 5);
    printf("%d\n", myCircularQueueFront(cq));
}
#pragma once
#include<stdlib.h>
#include<assert.h>
#include<stdio.h>
#include<stdbool.h>

typedef int HPDataType;
typedef struct Heap
{
	HPDataType* a;
	int size;
	int capacity;
}HP;
void Swap(HPDataType* a, HPDataType* b);
void HPInit(HP* php);
void HPDestory(HP* php);
void AdjustUp(HPDataType*a,int child);
void AdjustDown(HPDataType* a, int n, int parent);
void HPPush(HP* php, HPDataType x);
void HPPop(HP* php);
HPDataType HPTop(HP* php);
bool HPEmpty(HP* php);
void HeapSort(int* a, int n);



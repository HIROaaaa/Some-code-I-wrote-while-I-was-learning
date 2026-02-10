#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
#include<time.h>
typedef int HPDataType;
typedef struct Heap
{
	HPDataType* a;
	int size;
	int capacity;
}HP;
typedef int SDataType;
void AdjustDown(HPDataType* a, int n, int parent);
void InsertSort(SDataType* a, int n);
void Swap(HPDataType* a, HPDataType* b);
void HeapSort(int* a, int n);
void BubbleSort(int* a, int n);
void ShellSort(int *a2,int N);
void SelectSort(int *a3,int N);
void QuickSort(int* a, int left, int right);
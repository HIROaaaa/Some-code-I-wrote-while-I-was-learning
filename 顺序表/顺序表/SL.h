#pragma once
#define INIT_CAPACITY 4
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
typedef int SLDataType;
// 动态顺序表 -- 按需申请
typedef struct SeqList
{
	SLDataType* arr;
	int size;
	int capacity;
}SL;

//初始化和销毁
void SLInit(SL* ps);
void SLDestroy(SL* ps);
void SLPrint(SL* ps);
////扩容
void SLCheckCapacity(SL* ps);
////头部插?删除 / 尾部插?删除
void SLPushBack(SL* ps, SLDataType x);
void SLPopBack(SL* ps);
void SLPushFront(SL* ps, SLDataType x);
void SLPopFront(SL* ps);
//
////指定位置之前插?/删除数据
void SLInsert(SL* ps, int pos, SLDataType x);
//
void SLErase(SL* ps, int pos);
int SLFind(SL* ps, SLDataType x);
#define _CRT_SECURE_NO_WARNINGS
#include"SL.h"
void SLInit(SL* ps)
{
	ps->arr = NULL;
	ps->capacity = ps->size = 0;
}
void SLDestroy(SL* ps)
{
	if (ps->arr)
	{
		free(ps->arr);
	}
	ps->arr = NULL;
	ps->capacity = ps->size = 0;
}
void SLCheckCapacity(SL* ps)
{
	assert(ps);
	if (ps->capacity == ps->size)
	{
		int Newcapacity = ps->capacity == 0 ? 4 : 2 * ps->capacity;
		SLDataType* tmp = (SLDataType*)realloc(ps->arr, Newcapacity*sizeof(SLDataType));
		if (tmp == NULL)
		{
			perror("relloc fail!");
			exit(1);
		}
		ps->arr = tmp;
		ps->capacity = Newcapacity;
	}
}
void SLPushBack(SL* ps, SLDataType x)
{
	assert(ps);
	SLCheckCapacity(ps);
	ps->arr[ps->size++] = x;
}
void SLPrint(SL* ps)
{
	assert(ps);
	// 遍历有效元素（size是有效个数，不是capacity）
	for (int i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->arr[i]);
	}
	printf("\nsize: %d, capacity: %d\n", ps->size, ps->capacity);
}
void SLPushFront(SL* ps, SLDataType x)
{
	assert(ps);
	SLCheckCapacity(ps);
	for (int i = ps->size; i > 0; i--)
	{
		ps->arr[i] = ps->arr[i - 1];
	}
	ps->arr[0] = x;
	ps->size++;
}
void SLPopBack(SL* ps)
{
	assert(ps);
	ps->size--;
}
void SLPopFront(SL* ps)
{
	assert(ps);
	for (int i =0; i < ps->size-1; i++)
	{
		ps->arr[i] = ps->arr[i + 1];
	}
	ps->size--;
}
void SLInsert(SL* ps, int pos, SLDataType x)
{
	assert(ps);
	SLCheckCapacity(ps);
	for (int i = ps->size; i > pos; i--)
	{
		ps->arr[i] = ps->arr[i - 1];
	}
	ps->size++;
	ps->arr[pos] = x;
}
void SLErase(SL* ps, int pos)
{
	assert(ps);
	if (pos<ps->size)
	{
		for (int i = pos; i < ps->size; i++)
		{
			ps->arr[i] = ps->arr[i + 1];
		}
		ps->size--;
	}
	else
	{
		printf("没有元素可以删除");
		exit(1);
	}
}
int SLFind(SL* ps, SLDataType x)
{
	assert(ps);
	for (int i = 0; i < ps->size; i++)
	{
		if (ps->arr[i]==x)
			return i;
	}
	return -1;
}
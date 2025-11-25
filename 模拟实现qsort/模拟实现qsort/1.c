#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<string.h>
int cmp(const void* p1,const void* p2)
{
	return (*(int*)p1 - *(int*)p2);
}
void _swap(void* p1, void* p2, int len)
{
	for (int i = 0; i < len; i++)
	{
		char tmp = *((char*)p1+i);
		*((char*)p1+i) = *((char*)p2+i);
		*((char*)p2+i) = tmp;
	}
}
void bubble(void*base,int count,int size,int(*cmp)(void*,void*) )
{
	for (int i = 0; i < count - 1; i++)
	{
		for (int j = 0; j < count - i - 1; j++)
		{
			if (cmp((char*)base + j * size, (char*)base + (1 + j) * size) > 0)
			{
				_swap((char*)base + j * size, (char*)base + (1 + j) * size, size);
			}
		}
	}
}
int main()
{
	int arr[] = { 'a','b','e','c'};
	bubble(arr, sizeof(arr) / sizeof(arr[0]), sizeof(arr[0]), cmp);
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		printf("%d   ", arr[i]);
	}
	return 0;
}
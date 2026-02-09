#define _CRT_SECURE_NO_WARNINGS
#include"Sort.h"
void AdjustDown(HPDataType* a, int n, int parent)
{
	int child = parent * 2 + 1;
	while (child < n)
	{
		if (child + 1 < n && a[child] > a[child + 1])
		{
			child++;
		}
		if (a[child] < a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}
void InsertSort(SDataType* a, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int end = i;
		int tmp = a[end + 1];
		while (end >= 0)
		{
			if (tmp < a[end])
			{
				a[end+1] = a[end];
				end--;
			}
			else
			{
				break;
			}
		}
		a[end+1] = tmp;
	}
}
void Swap(HPDataType* a, HPDataType* b)
{
	HPDataType tmp = *a;
	*a = *b;
	*b = tmp;
}
void HeapSort(int* a, int n)
{
	/*for (int i = 1; i < n; i++)
	{
		AdjustUp(a, i);
	}*/
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(a, n, i);
	}
	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		AdjustDown(a, end, 0);
		end--;
	}
}
void BubbleSort(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		int flag = 0;
		for (int j = 0; j < n-i-1; j++)
		{
			if (a[j] > a[j + 1])
			{
				Swap(&a[j], &a[j + 1]);
				flag = 1;
			}
		}
		if (flag == 0)
		{
			break;
		}
	}
}
void ShellSort(int a2[], int N)
{
	int gap = N;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		for (int i = 0; i < N - gap; i++)
		{
			int end = i;
			int tmp = a2[end + gap];
			while (end >= 0)
			{
				if (tmp < a2[end])
				{
					a2[end + gap] = a2[end];
					end -= gap;
				}
				else
				{
					break;
				}
			}
			a2[end + gap] = tmp;
		}
	}
}
void SelectSort(int a3[],int N)
{
	int begin = 0, end = N - 1;
	int max = end, min = begin;
	while (begin < end)
	{
		max = end;
		min = begin;
		for (int j = begin + 1; j <= end; j++)
		{
			if (a3[j] < a3[min])
			{
				min = j;
			}
			if (a3[j] > a3[max])
			{
				max = j;
			}
		}
		Swap(&a3[min], &a3[begin]);
		if (max == begin)
		{
			max = min;
		}
		Swap(&a3[max], &a3[end]);
		begin++;
		end--;
	}
}
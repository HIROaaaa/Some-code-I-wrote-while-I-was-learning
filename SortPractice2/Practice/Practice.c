#define _CRT_SECURE_NO_WARNINGS
#include "Stack.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
void Swap(int* n, int* m)
{
	int tmp = *n;
	*n = *m;
	*m = tmp;
}
void InsertSort(int* a, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int end = i;
		int tmp = a[end + 1];
		while (end >= 0)
		{
			if (a[end] > tmp)
			{
				a[end + 1] = a[end];
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
void ShellSort(int* a, int n)
{
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		for (int i = 0; i < n - gap; i++)
		{
			int end = i;
			int tmp = a[end + gap];
			while (end >= 0)
			{
				if (a[end] > tmp)
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else
				{
					break;
				}
			}
			a[end + gap] = tmp;
		}
	}
}
void SelectSort(int* a, int n)
{
	int begin = 0, end = n - 1;
	int maxi = end;
	int mini = begin;
	while (begin < end)
	{
		maxi = end;
		mini = begin;
		for (int i = begin + 1; i < end; i++)
		{
			if (a[i] > a[maxi])
			{
				maxi = i;
			}
			if (a[i] < a[mini])
			{
				mini = i;
			}
		}
		Swap(&a[begin], &a[mini]);
		if (maxi == begin)
		{
			maxi = mini;
		}
		Swap(&a[end], &a[maxi]);
		begin++;
		end--;
	}
}
void AdjustDown(int* a,int n,int parent)
{
	int child = parent * 2 + 1;
	while (child<n)
	{
		if (child + 1 < n && a[child] < a[child + 1])
		{
			child++;
		}
		if (a[parent] < a[child])
		{
			Swap(&a[parent], &a[child]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}
void HeapSort(int* a, int n)
{
	//½¨¶Ñ
	for (int i = (n - 1 - 1) / 2; i>0; i--)
	{
		AdjustDown(a, n, i);
	}
	//ÅÅÐò
	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		AdjustDown(a, end, 0);
		end--;
	}
}
BubbleSort(int* a, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int k = 1;
		for (int j = 0; j < n-i-1; j++)
		{
			if (a[j] > a[j + 1])
			{
				Swap(&a[j], &a[j + 1]);
				k = 0;
			}
		}
		if (k == 1)
		{
			break;
		}
	}
}
int GetMidi(int* a, int left, int right)
{
	int midi = (left + right) / 2;
	if (a[midi] > a[left])
	{
		if (a[midi] < a[right])
		{
			return midi;
		}
		else if (a[left] > a[right])
		{
			return left;
		}
		else
		{
			return right;
		}
	}
	else
	{
		if (a[midi] > a[right])
		{
			return midi;
		}
		else if (a[right] < a[left])
		{
			return left;
		}
		else
		{
			return right;
		}
	}
}
int PartSort1(int* a, int left, int right)
{
	int begin = left, end = right;
	int keyi = left;
	int midi = GetMidi(a, left,right);
	Swap(&a[keyi], &a[midi]);
	while (begin < end)
	{
		if (begin < end && a[end] >= a[keyi])
		{
			end--;
		}
		if (begin < end && a[begin] <= a[keyi])
		{
			begin++;
		}
		Swap(&a[end], &a[begin]);
	}
	Swap(&a[begin], &a[keyi]);
	return begin;
}
int PartSort2(int* a, int left, int right)
{
	int keyi = left;
	int prev = left;
	int cur = prev + 1;
	while (cur <= right)
	{
		if (a[keyi] > a[cur] && ++prev != cur)
		{
			Swap(&a[prev], &a[cur]);
		}
		cur++;
	}
	Swap(&a[keyi], &a[prev]);
	return prev;
}
void QuickSort(int* a, int left, int right)
{
	if (left >= right)
	{
		return;
	}
	if (right - left + 1 < 10)
	{
		InsertSort(a+left, right - left + 1);
	}
	else
	{
		int keyi = PartSort1(a, left, right);
		//int keyi = PartSort2(a, left, right);
		QuickSort(a, left, keyi - 1);
		QuickSort(a, keyi + 1, right);
	}
}
void _QuickSort(int* a, int left, int right)
{
	if (left >= right)
	{
		return;
	}
	if (right - left + 1 < 10)
	{
		InsertSort(a + left, right - left + 1);
	}
	else
	{
		int midi = GetMidi(a, left, right);
		Swap(&a[midi], &a[left]);
		int key = a[left];
		int cur = left + 1;
		int begin = left, end = right;
		while (cur <= right)
		{
			if (a[cur] > key)
			{
				Swap(&a[right], &a[cur]);
				right--;
			}
			else if (a[cur] < key)
			{
				Swap(&a[left], &a[cur]);
				left++;
				cur++;
			}
			else
			{
				cur++;
			}
		}
		_QuickSort(a, begin, left - 1);
		_QuickSort(a, right + 1, end);
	}
}
void QuickSortNonR(int* a, int left, int right)
{
	ST st;
	STInit(&st);
	STPush(&st, right);
	STPush(&st, left);
	while (!STEmpty(&st))
	{
		int begin = STTop(&st);
		STPop(&st);
		int end = STTop(&st);
		STPop(&st);
		int keyi = PartSort2(a, begin, left);
		if (keyi + 1 < end)
		{
			STPush(&st, end);
			STPush(&st, keyi + 1);
		}
		if (keyi - 1 > begin)
		{
			STPush(&st, keyi - 1);
			STPush(&st, begin);
		}
	}
	STDestory(&st);
}
void _MergeSort(int* a, int* tmp, int left, int right)
{
	if (left == right)
	{
		return;
	}
	int mid = (left + right) / 2;
	_MergeSort(a, tmp, left, mid);
	_MergeSort(a, tmp, mid + 1, right);
	int begin1 = left, end1 = mid;
	int begin2 = mid + 1, end2 = right;
	int i = left;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] < a[begin2])
		{
			tmp[i++] = a[begin1++];
		}
		else
		{
			tmp[i++] = a[begin2++];
		}
	}
	while (begin1 <= end1)
	{
		tmp[i++] = a[begin1++];
	}
	while (begin2 <= end2)
	{
		tmp[i++] = a[begin2++];
	}
	memcpy(a+left, tmp+left, sizeof(int) * (right - left + 1));
}
void MergeSort(int* a, int n)
{
	int* tmp = (int*)malloc(n * sizeof(int));
	if (tmp == NULL)
	{
		perror("malloc fail");
		return;
	}
	_MergeSort(a, tmp, 0, n - 1);
	free(tmp);
	tmp = NULL;
}
void MergeSortNonR(int* a, int n)
{
	int* tmp = (int*)malloc(n * sizeof(int));
	if (tmp == NULL)
	{
		perror("malloc fail");
		return;
	}
	int gap = 1;
	while (gap < n)
	{
		for (int i = 0; i < n; i += gap * 2)
		{
			int begin1 = i, end1 = i + gap - 1;
			int begin2 = i + gap, end2 = i + 2 * gap - 1;
			if (begin2 >= n)
			{
				break;
			}
			if (end2 >= n)
			{
				end2 = n - 1;
			}
			int j = i;
			while (begin1 <= end1 && begin2 <= end2)
			{
				if (a[begin1] < a[begin2])
				{
					tmp[j++] = a[begin1++];
				}
				else
				{
					tmp[j++] = a[begin2++];
				}
			}
			while (begin1 <= end1)
			{
				tmp[j++] = a[begin1++];
			}
			while (begin2 <= end2)
			{
				tmp[j++] = a[begin2++];
			}
			memcpy(a + i, tmp + i, sizeof(int) * (end2 - i + 1));
		}
		gap *= 2;
	}
	free(tmp);
	tmp = NULL;
}
void CountSort(int* a, int n)
{
	int max = a[0];
	int min = a[0];
	for (int i = 0; i < n; i++)
	{
		if (max < a[i])
		{
			max = a[i];
		}
		if (min > a[i])
		{
			min = a[i];
		}
	}
	int range = max - min + 1;
	int* tmp = (int*)calloc(range, sizeof(int));
	if (tmp == NULL)
	{
		perror("calloc fail");
		return;
	}
	for (int i = 0; i < n; i++)
	{
		tmp[a[i] - min]++;
	}
	int j = 0;
	for (int i = 0; i < range; i++)
	{
		while (tmp[i]--)
		{
			a[j++] = i + min;
		}
	}
	free(tmp);
	tmp = NULL;
}
int main()
{
	return 0;
}
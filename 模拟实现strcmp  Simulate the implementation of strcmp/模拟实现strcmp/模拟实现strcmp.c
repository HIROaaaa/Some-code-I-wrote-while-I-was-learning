#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int bin_search(int arr[], int left, int right, int key)
{
	while (left<=right)
	{
		int mid = (left + right) / 2;
		if (arr[mid] < key)
		{
			left=mid+1;
		}
		else if (arr[mid] > key)
		{
			right=mid-1;
		}
		else if (arr[mid] == key)
		{
			
			return mid;
		}
	}
	return -1;
}
int main()
{
	int arr[] = { 0,1,2,3,4,5,6,7,8,9,10 };
	int num = 0;
	int len = sizeof(arr) / sizeof(arr[0]);
	printf("请输入要找的数：");
	scanf("%d", &num);
	int result = bin_search(arr, 0, len - 1, num);
	if (result == -1)
	{
		printf("没找到");
	}
	else
	{
		printf("找到了，是:%d", result);
	}
	return 0;
}
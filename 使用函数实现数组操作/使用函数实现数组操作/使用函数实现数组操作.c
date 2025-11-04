#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
void init(int arr[],int len)
{
	int i = 0;
	for (i; i < len; i++)
	{
		arr[i] = 0;
	}
}
void print(int arr[],int len)
{
	for (int i = 0; i < len; i++)
		printf("%d ", arr[i]);
	printf("\n");
}
void reverse(int arr[], int len)
{
	int left = 0;
	int right = len - 1;
	while (left < right)
	{
		int temp = arr[left];
		arr[left] = arr[right];
		arr[right] = temp;
		left++;
		right--;
	}
}
int main()
{
	int arr[] = {1,2,3,4,5,6,7,8,9,0};
	int len = sizeof(arr) / sizeof(arr[0]);
	init(arr,len);
	print(arr,len);
	int arr2[] = { 1,2,3,4,5,6,7,8,9,0 };
	reverse(arr2, len);
	print(arr2, len);

}
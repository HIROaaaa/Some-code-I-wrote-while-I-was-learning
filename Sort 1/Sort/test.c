#define _CRT_SECURE_NO_WARNINGS
#include"Sort.h"
int main()
{
	int a[] = { 1,3,1,124,51,4,26,412,1,6,312 };
	InsertSort(a, 9);
	for (int i = 0; i < 9; i++)
	{
		printf("%d ", a[i]);
	}
	return 0;
}
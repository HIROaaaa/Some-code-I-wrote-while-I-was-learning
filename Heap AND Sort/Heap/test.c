#define _CRT_SECURE_NO_WARNINGS
#include"Heap.h"
#include<time.h>
int main()
{
	//int a[] = { 0,4,65,12,431,5 };
	//HP hp;
	//HPInit(&hp);
	//for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
	//{
	//	HPPush(&hp, a[i]);
	//}
	//while (!HPEmpty(&hp))
	//{
	//	printf("%d\n", HPTop(&hp));
	//	HPPop(&hp);
	//}



	/*HPDestory(&hp);*/
	//int a2[] = { 1,3,21,4,1,51,13,4,12 };
	//HeapSort(a2,sizeof(a2)/sizeof(a2[0]));



	srand(time(0));
	const char* file = "data.txt";
	FILE* fin = fopen(file, "w");
	if (fin == NULL)
	{
		perror("fopen fail");
		return;
	}
	for (int i = 0; i < 100000; i++)
	{
		int x = rand()+i;
		fprintf(fin, "%d\n", x);
	}
	fclose(fin);
	fin = fopen("data.txt", "r");
	//建堆
	int k;
	scanf("%d", &k);
	int* kminheap = (int*)malloc(sizeof(int) * k);
	if (kminheap == NULL)
	{
		perror("malloc fail");
		return;
	}
	for (int i = 0; i < k; i++)
	{
		fscanf(fin, "%d", &kminheap[i]);
	}
	for (int i = (k - 1) / 2; i >= 0; i--)
	{
		AdjustDown(kminheap,k,i);
	}
	int x = 0;
	while (fscanf(fin , "%d", &x)==1)
	{
		if (kminheap[0] < x)
		{
			kminheap[0] = x;
			AdjustDown(kminheap,k,0);
		}
	}
	printf("最大前%d个数：\n", k);
	for (int i = 0; i < k; i++)
	{
		printf("%d\n", kminheap[i]);
	}

	return 0;
}
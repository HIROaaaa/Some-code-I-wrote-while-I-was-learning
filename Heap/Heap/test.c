#define _CRT_SECURE_NO_WARNINGS
#include"Heap.h"
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
	int a2[] = { 1,3,21,4,1,51,13,4,12 };
	HeapSort(a2,sizeof(a2)/sizeof(a2[0]));
	return 0;
}
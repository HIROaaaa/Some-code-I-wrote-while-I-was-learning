#define _CRT_SECURE_NO_WARNINGS
#include"SL.h"
void test01()
{
	SL sl;
	SLInit(&sl);
	SLPushBack(&sl, 1);
	SLPushBack(&sl, 2);
	SLPushBack(&sl, 3);
	SLPushBack(&sl, 4);
	SLPushBack(&sl, 5);
	SLPushFront(&sl, 8);
	SLPushFront(&sl, 6);
	SLPushFront(&sl, 7);
	SLPushFront(&sl, 9);



	SLPrint(&sl);
	SLPopBack(&sl);
	SLPrint(&sl);
	SLPopFront(&sl);
	SLPrint(&sl);
	SLInsert(&sl, 5, 10);
	SLPrint(&sl);
	SLErase(&sl, 6);
	SLPrint(&sl);
	int pos = SLFind(&sl, 4);

	printf("%d", pos);

}
int main()
{
	test01();
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include "Stack.h"
int main()
{
	ST s;
	STInit(&s);
	STPush(&s, 1);
	STPush(&s, 4);
	STPush(&s, 6);
	STPush(&s, 3);
	STPush(&s, 7);
	printf("%d", STTop(&s));
	return 0;
}
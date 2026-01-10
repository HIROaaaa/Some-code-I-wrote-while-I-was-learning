#define _CRT_SECURE_NO_WARNINGS
#include"List.h"
int main()
{
	LTNode* plist = LTInit();	
	LTPushBack(plist, 1);
	LTPushBack(plist, 4);
	LTPushBack(plist, 5);
	LTPushBack(plist, 3);
	LTPrint(plist);
	LTPushFront(plist, 10);
	LTPushFront(plist, 7);
	LTPushFront(plist, 12);
	LTPrint(plist);
	LTPopBack(plist);
	LTPrint(plist);
	LTPopFront(plist);
	LTPrint(plist);
	LTNode* find = LTFind(plist, 4);
	LTInsert(find, 10);
	LTPrint(plist);
	LTErase(find);
	LTPrint(plist);
	plist = NULL; 
	LTPrint(plist);
}

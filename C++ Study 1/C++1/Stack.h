#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>

namespace bit
{
	typedef int STDataType;
	typedef struct Stack
	{
		STDataType* a;
		int top;
		int capacity;
	}ST;

	void STInit(ST* ps, int n=4); 
	void STDestroy(ST* ps);

	void STPush(ST* ps, STDataType x);
	void STPop(ST* ps);
	STDataType STTop(ST* ps);
	int STSize(ST* ps);
	bool STEmpty(ST* ps);
}
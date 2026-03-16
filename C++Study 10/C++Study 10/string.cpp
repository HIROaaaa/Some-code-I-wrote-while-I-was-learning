#define _CRT_SECURE_NO_WARNINGS
#include"string.h"
namespace hiro
{
	void test_string1()
	{
		string s1 = "hello world";
		for (int i = 0; i < s1.size(); i++)
		{
			cout << s1[i];
		}
		cout << endl;
	}
}

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<list>
#include<algorithm>
using namespace std;
void test1()
{
	list<int>lt;
	lt.push_back(1);
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(3);
	lt.push_back(4);
	lt.push_back(4);
	lt.push_back(4);
	lt.push_back(5);
	lt.push_back(1);
	lt.push_back(3);
	list<int>::iterator it = lt.begin();
	while (it!=lt.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
	for (auto i : lt)
	{
		cout << i << " ";
	}
	cout << endl;
	
	lt.sort();
	lt.unique();//去重  但是要求链表有序
	for (auto i : lt)
	{
		cout << i << " ";
	}
	cout << endl;
	lt.remove(1);  //删除某个值
	for (auto i : lt)
	{
		cout << i << " ";
	}
	cout << endl;
}
struct A
{
public:
	A(int a1=1,int a2=2)
		:_a1(a1)
		,_a2(a2)
	{ }
private:
	int _a1;
	int _a2;
};
void test2()
{
	list<A> lt;
	A aa1;
	lt.push_back(aa1);
	lt.push_back(A(3,3));
	//支持直接传构造A的参数
	lt.emplace_back(3, 3);  //emplace_back还可以这样赋值
}
int main()
{
	test1();
	return 0;
}
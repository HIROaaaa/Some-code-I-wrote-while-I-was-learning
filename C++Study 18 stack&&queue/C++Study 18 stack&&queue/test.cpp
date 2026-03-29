#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include"PriorityQueue.h"
using namespace hiro;
using namespace std;
template <class T>

//仿函数   重载了()  对象可以像函数一样使用
class Less 
{
public:
	bool operator()(T x, T y)
	{
		return x < y;
	}
};
int main()
{
	Less<int> LessFunc;
	cout << LessFunc(1, 2) << endl;

	cout << LessFunc.operator()(1, 2) << endl;
	priority_queue<int,vector<int>> pq;   //大的优先级高   底层是堆
	                            //加上greater之后变成小堆
	pq.push(1);
	pq.push(2);
	pq.push(3);
	pq.push(10);
	pq.push(5);
	pq.push(4);
	while (!pq.empty())
	{
		cout << pq.top() << " ";
		pq.pop();
	}
	cout << endl;
	return 0;
}
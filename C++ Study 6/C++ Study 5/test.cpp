#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
class A
{
public:
	/*A(int a = 0,int b=0)
		: _a1(a)
		, _a2(b)
	{
		cout << "A():" << this << endl;
	}*/
	A(int a, int b = 0)
		: _a1(a)
		, _a2(b)
	{
		cout << "A():" << this << endl;
	}
	~A()
	{
		cout << "~A():" << this << endl;
	}
private:
	int _a1;
	int _a2;
};
struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int x)
		:val(x)
		,next(nullptr)
	{ }
};
int main()
{
	////new和delete
	//int* ptr1 = new int;
	//int* ptr2 = new int[10];//10个int类型的空间
	//int* ptr3 = new int(10);//赋值为10
	//delete ptr1;
	//delete[]ptr2; 
	////申请对象+初始化
	//int* ptr4 = new int[10] {0};
	//int* ptr5 = new int[10] {1,2,4,5,6};
	//delete[] ptr4, ptr5;

	//更快更方便
	//ListNode* n1 = new ListNode(1);
	//ListNode* n2 = new ListNode(2);
	//ListNode* n3 = new ListNode(3);
	//n1->next = n2;
	//n2->next = n3;
 
	
	////A* p1 = new A();
	////A* p2 = new A(1);
	////A* p3 = new A(1, 2);
	A* p1 = new A[3]{ {1,1},{2,2},{3,3} };//隐式类型转换
	A* p2= new A[3]{ A(1,1),A(2,2),A(3,3)};//构造
	delete[] p1;


	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"Stack.h"
using namespace std;
//全缺省
void Func1(int a = 10, int b = 20, int c = 30)
{
	cout << "a= " << a << endl;
	cout << "b= " << b << endl;
	cout << "c= " << c << endl<<endl;
}
//半缺省
void Func2(int a, int b = 20, int c = 30)
{
	cout << "a= " << a << endl;
	cout << "b= " << b << endl;
	cout << "c= " << c << endl<<endl;
}
//函数重载
int ADD(int left, int right)
{
	cout << "int ADD(int left, int right)" << endl;
	return left + right;
}
double ADD(double left, double right)
{
	cout << "double ADD(double left, double right)" << endl;
	return left + right;
}

//是重载但是调用有问题
void f1()
{
	return;
}
void f1(int a = 10)
{
	return;
}

//可以这样
namespace hiro
{
	void f2()
	{
		return;
	}
}
void f2(int a = 10);

int main()
{
	int a = 0;
	double b = 0.1;
	char c = 'x';

	//用来提高io效率
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);


	//引用
	int m = 0;
	int& n = m;
	int& p = m;
	p++;
	cout << p << endl;
	n++;
	cout << m << endl;

	//重载
	int i = ADD(1, 2);
	double d = ADD(1.5, 3.4);
	cout << i <<endl <<d << endl;

	/*Func1(1, 2, 3);
	Func1();
	Func2(1,2,3);
	Func2(1, 2);
	Func2(1);*/

	//cin >> a >> b >> c;
	//cout << a << ' ' << b << " " << c << endl;
	//std::cout << a << ' ' << b << " " << c << std::endl;
	return 0;
}
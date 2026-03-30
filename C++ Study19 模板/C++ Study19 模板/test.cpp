#define _CRT_SECURE_NO_WARNINGS
#include<string>
#include<iostream>
#include<array>
using namespace std;
//#define N 5

//非类型模板      可以给缺省值   布尔类型也算是整型
template <size_t N=10,bool flag=false>
class stack
{
private:
	int a[N];
	int _top;
};
////c++20 才能支持用浮点型   
//template<double D>
//class A
//{
//
//};
////类类型20之后也不行
//template<string N>
//class B
//{
//
//};
int main()
{
	stack<> s0;   //最好是这样写
	//stack s0;   //这样写老的标准不支持

	array<int, 10> a1;  //静态数组    需要  <array>头文件
	int a3[10];
	//这里越界检查是抽查   只检查越界之后的两个位置   并且读不检查，只有写会检查
	cout << a3[100] << endl;
	//x64就检查的出来了   x86检查不出来
	a3[12] = 10;

	//这里的静态数组就检查的出来
	//这里是函数调用，直接assert就可以检查的出来越界
	//a1[12] = 10;

	//静态数组建立在栈上，效率更高   比vector在堆上开要高 
	return 0;
}
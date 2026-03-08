#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cassert>
using namespace std;
//class Time
//{
//public:
//	Time(int hour)
//		:_hour(hour)
//	{
//		cout << "Time()" << endl;
//	}
//private:
//	int _hour;
//};
class Date
{
public:
	Date(int year, int month, int day)
		:_year(year)//初始化列表
		,_month(month)//括号里可以放初始值，也可以放表达式
		,_day(day)
		//,x(1)//const类型的初始化要用初始化列表
		//,y(day)//引用也要
		//,_time(1)//没有默认构造的自定义类型必须用
		//,_ptr((int*)malloc(sizeof(int)*5))//可以和函数混着用，比如这样
		////,_year(year)每个成员变量只能出现一次，像这样在写一次就不行
	{
		//if (_ptr == NULL)
		//{
		//	perror("malloc fail");
		//	return;
		//}
		//else
		//{

		//}
	}
	void Print() const
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}
private:
	//声明
	int _year=1;
	int _month=1;
	int _day=1;
	//int* _ptr=(int*)malloc(sizeof(int)*5);//这种也可以给缺省值
	//Time _time=1;//这里也是
	////必须在初始化列表初始化
	//const int x;
	//int& y;
};
int main()
{
	Date d1;
	d1.Print();
	return 0;
}
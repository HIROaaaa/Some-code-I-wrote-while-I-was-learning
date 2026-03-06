#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
class Date
{
public:
	Date(int year = 2026, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	//拷贝构造函数，要用引用拷贝，不然会造成无穷递归
	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	//运算符重载
	bool operator==(const Date& d2)//可以用引用来拷贝来节省空间
	{
		return _year == d2._year &&
			_month == d2._month &&
			_day == d2._day;
	}
	//赋值运算符重载
	Date operator=(const Date& d)///这里直接传值也可以，不会无穷递归
	{
		_year = d._year;
		_month = d._month;	
		_day = d._day;
		return *this;
	}
private:
	int _year;
	int _month;
	int _day;
};
int main()
{
	Date d1(2026, 3, 6);
	Date d2;
	//赋值运算符重载
	d2 = d1;
	//拷贝构造
	Date d3 = d1;
}
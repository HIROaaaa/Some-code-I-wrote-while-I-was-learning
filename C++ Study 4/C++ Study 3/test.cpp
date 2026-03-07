#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cassert>
using namespace std;
class Date
{
	//友元函数声明
	friend ostream& operator<<(ostream& out, const Date& d);
	friend istream& operator>>(istream& in, Date& d);
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
	//赋值运算符重载
	Date& operator=(const Date& d)///这里直接传值也可以，不会无穷递归  //应该返回Date&，支持链式赋值（d1=d2=d3）
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
		return *this;
	}
	int GetDay()
	{
		assert(_month > 0 && _month < 13);
		static int arr[] = { -1,31,28,31,30,31,30,31,31,30,31,30,31 };
		if (_year % 4 == 0 && _year % 400 != 0 || _year % 100 == 0 && _month == 2)
		{
			return 29;
		}
		return arr[_month];
	}
	Date& operator+=(int day)
	{
		if (day < 0)
		{
			return *this -= day;
		}
		_day += day;
		while (_day > GetDay())
		{
			_day -= GetDay();
			++_month;
			if (_month == 13)
			{
				++_year;
				_month = 1;
			}
		}
		return *this;
	}
	Date operator+(int day)const
	{
		Date tmp = *this;
		tmp += day;
		return tmp;
	}
	Date& operator-=(int day)
	{
		if (day < 0)
		{
			return *this += -day;
		}
		_day -= day;
		while (_day <= 0)
		{
			--_month;
			if (_month == 0)
			{
				--_year;
				_month = 12;
			}
			_day += GetDay();

		}
		return *this;
	}
	Date operator-(int day)const
	{
		Date tmp = *this;
		tmp -= day;
		return tmp;
	}
	Date& operator++()
	{
		*this += 1;

		return *this;
	}

	// d1++
	Date operator++(int)
	{
		Date tmp(*this);
		*this += 1;

		return tmp;
	}
	int operator-(const Date& d)const
	{
		Date max = *this;
		Date min = d;
		int flag = 1;
		if (*this < d)
		{
			max = d;
			min = *this;
			flag = -1;
		}

		int n = 0;
		while (min != max)
		{
			++min;
			++n;
		}

		return n * flag;
	}
	//d1<d2
	bool operator<(const Date& d)const
	{
		if (_year < d._year)
		{
			return true;
		}
		else if (_year == d._year)
		{
			if (_month < d._month)
			{
				return true;
			}
			else if (_month == d._month)
			{
				return _day < d._day;
			}
		}
		return false;
	}
	bool operator<=(const Date& d)const
	{
		return *this < d || *this == d;
	}

	bool operator>(const Date& d)const
	{
		return !(*this <= d);
	}

	bool operator>=(const Date& d)const
	{
		return !(*this < d);
	}

	bool operator==(const Date& d)const
	{
		return _year == d._year
			&& _month == d._month
			&& _day == d._day;
	}
	bool operator!=(const Date& d)const
	{
		return !(*this == d);
	}
	bool CheckDate()const
	{
		if (_month < 1 || _month > 12
			|| _day < 1 || _day > GetDay())
		{
			return false;
		}
		else
		{
			return true;
		}
	}
private:
	int _year;
	int _month;
	int _day;
};
ostream& operator<<(ostream& out, const Date& d)
{
	out << d._year << "年" << d._month << "月" << d._day << "日" << endl;
	//cout从左往右调用，所以这里要返回out来继续插入下一个值
	return out;
}
istream& operator>>(istream& in, Date& d)
{
	while (1)
	{
		cout << "请输出年月日:";
		in >> d._year >> d._month >> d._day;
		if (!d.CheckDate())
		{
			cout << "输入非法日期，请重新输入" << endl;
		}
		else
		{
			break;
		}
	}
	return in;
}
int main()
{
	//Date d1(2026, 3, 6);
	//Date d2;
	////赋值运算符重载
	//d2 = d1;
	//int m = 0;
	//int n = 2;
	//m = n;
	////拷贝构造
	//Date d3 = d1;
	Date d1, d2;
	cin >> d1 >> d2;
	cout << d1 - d2 << endl;
}
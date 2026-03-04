#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cassert>
using namespace std;

typedef int STDataType;
class Stack
{
public:
	// 成员函数
	//构造函数
	Stack(int n = 4)
	{
		_a = (STDataType*)malloc(sizeof(STDataType) * n);
		if (nullptr == _a)
		{
			perror("malloc申请空间失败");
			return;
		}

		_capacity = n;
		_top = 0;
	}
	//析构函数
	//后生成的先析构
	~Stack()
	{
		free(_a);
		_a = nullptr;
		_capacity = _top = 0;
	}
	void Push(STDataType x)
	{
		if (_top == _capacity)
		{
			int newcapacity = _capacity * 2;
			STDataType* tmp = (STDataType*)realloc(_a, newcapacity *
				sizeof(STDataType));
			if (tmp == NULL)
			{
				perror("realloc fail");
				return;
			}

			_a = tmp;
			_capacity = newcapacity;
		}

		_a[_top++] = x;
	}

	void Pop()
	{
		assert(_top > 0);
		--_top;
	}

	bool Empty()
	{
		return _top == 0;
	}

	int Top()
	{
		assert(_top > 0);

		return _a[_top - 1];
	}

	void Destroy()
	{
		free(_a);
		_a = nullptr;
		_top = _capacity = 0;
	}
private:
	// 成员变量
	STDataType* _a;
	size_t _capacity;
	size_t _top;
};
class Queue
{
	//这里不写析构函数会自动调用两个栈的析构函数
	Stack st1;
	Stack st2;
};
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
	bool operator==(Date& d2)//可以用引用来拷贝来节省空间
	{
		return _year == d2._year &&
			_month == d2._month &&
			_day == d2._day;
	}

private:
	int _year;
	int _month;
	int _day;
};
int main()
{
	//Stack s;
	//s.Push(1);
	//s.Push(2);
	//s.Push(3);
	//s.Push(4);

	//while (!s.Empty())
	//{
	//	printf("%d\n", s.Top());
	//	s.Pop();
	//}

	//s.Destroy();
	
	Date d1(2026,2,1);
	Date d2(2026,4,3);
	//operator==(d1, d2);
	d1 == d2;
	//编译器会自动转换成d1.operator==(d2);
	d1.operator==(d2);

	Date d3(d1);
	return 0;
}
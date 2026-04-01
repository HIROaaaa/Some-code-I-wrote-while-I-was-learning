#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;

//算法：复写零
class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int cur = 0;
        int des = -1;
        int n = arr.size();
        while (des < n)
        {
            if (arr[cur])des++;
            else des += 2;
            if (des >= n - 1) break;
            cur++;
        }
        if (des == n)
        {
            arr[n - 1] = 0;
            des -= 2;
            cur--;
        }
        while (des >= 0)
        {
            if (arr[cur])
                arr[des--] = arr[cur--];
            else
            {
                arr[des--] = arr[cur];
                arr[des--] = arr[cur--];
            }
        }
    }
};
class Person        //父类||基类
{ 
public:
	// 进⼊校园/图书馆/实验室刷⼆维码等⾝份认证
	void identity()
	{
		cout << "void identity()" << _name << endl;
	}
protected:
	string _name = "张三"; // 姓名
	string _address; // 地址
	string _tel; // 电话
	int _age = 18; // 年龄
};

		//继承方式↓           这里的Student是  子类||派生类
class Student : public Person   //类的继承     数据成员和成员函数都可以继承
{
public:
	// 学习
	void study()
	{
		// ...
	}

protected:
	int _stuid; // 学号
};

class Teacher : public Person
{
public:
	// 授课
	void teaching()
	{
		//...
	}
protected:
	string title; // 职称
};

int main()
{
	Student s;
	Teacher t;

	s.identity();
	t.identity();

	return 0;
}
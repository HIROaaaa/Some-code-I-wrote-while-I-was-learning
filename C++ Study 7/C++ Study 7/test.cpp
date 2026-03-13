#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
template <class T/* 或者用tpyename T */>
void Swap(T& a, T& b)
{
	T tmp = a;
	a = b;
	b = tmp;
}
template<class T>//这样用同样的模板参数没事
void func(T& a)
{

}
template <class T1,typename T2>//可以混着用这两个 
void func2(T1 a, T2 b)
{

}
//void func(T& a)  //一个tmplate只能跟着一个函数模板
//{
//
//}
template<class T>
T* func3(int a)
{
	return new T[a];//写在这里不知道是T是什么，必须显式实例化 
}

// 专门处理int的加法函数
int Add(int left, int right)
{
	return left + right;     //会优先调用已经存在的
}
// 通用加法函数
template<class T>
T Add(T left, T right)
{
	return left + right;
}
void Test()
{
	Add(1, 2); // 与非模板函数匹配，编译器不需要特化
	Add<int>(1, 2); // 调用编译器特化的Add版本
}

template<typename T>
class Stack
{
public:
	Stack(size_t capacity = 4)
	{
		_array = new T[capacity];
		_capacity = capacity;
		_size = 0;
	}
	~Stack()
	{
		delete[] _array;
		_array = nullptr;
		_capacity = _size = 0;
	}
	void Push(const T& data)
	{
		if (_size == _capacity)
		{
			T* tmp = new T[_capacity * 2];
			memcpy(tmp, _array, sizeof(T) * _size);
			delete[] _array;

			_array = tmp;
			_capacity *= 2;
		}
		_array[_size++] = data;
	}
private:
	T* _array;
	size_t _capacity;
	size_t _size;
};

//声明定义分离需要重新定义模板参数
//并且声明和定义不能分开到两个文件
//template<typename T>
//void Stack<T>::Push(const T& data)
//{
//	if (_size == _capacity)
//	{
//		T* tmp = new T[_capacity * 2];
//		memcpy(tmp, _array, sizeof(T) * _size);
//		delete[] _array;
//
//		_array = tmp;
//		_capacity *= 2;
//	}
//	_array[_size++] = data;
//}


void Test2()
{
	//类模板都是显式实例化，因为创建对象时不知道是什么类型
	Stack<int> st1;
	st1.Push(1);
	st1.Push(2);
	st1.Push(3);
	st1.Push(4);
	st1.Push(5);
	Stack<double> st2;
	st2.Push(1.1);
	st2.Push(1.2);
	st2.Push(1.3);
	st2.Push(1.4);
}
int main()
{
	int a = 1, b = 2;
	float c = 1.1, b = 1.2;
	Swap(a, b);
	//Swap(a, c);//这样不行，模板参数T只有一个
	func2(a, c);//这样就可以，因为有T1,T2两个模板参数
	int a1 = 10, a2 = 20;
	double d1 = 10.0, d2 = 20.0;
	Add(a1, a2);
	Add(d1, d2);
	//推导实例化
	cout << Add((double)a1, d1)<<endl;//可以在这里用强制类型转换来使用
	//显式实例化
	cout << Add<int>(a1, d1) << endl;//这里double会走隐式类型转换
	double* p1 = func3<double>(2);

	Test();//模板参数的匹配原则

	Test2();//类模板


	return 0;
}
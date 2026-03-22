#pragma once
#include<iostream>
#include<assert.h>
using namespace std;
namespace hiro
{
	template <class T>
	class vector
	{
	public:
		typedef T* iterator;
		typedef const T* const_iterator;
		iterator begin()
		{
			return _start;
		}
		iterator end()
		{
			return _finish;
		}
		const_iterator begin() const
		{
			return _start;
		}
		const_iterator end() const
		{
			return _finish;
		}
		void reserve(size_t n)
		{
			if (n > capacity())
			{
				size_t old_size = size();
				T* tmp = new T[n];
				memcpy(tmp, _start, size() * sizeof(T));
				delete[] _start;

				_start = tmp;
				_finish = tmp + old_size;
				_end_of_storage = tmp + n;
			}
		}
		size_t capacity()
		{
			return _end_of_storage - _start;
		}
		size_t size()
		{
			return _finish - _start;
		}
		size_t capacity()const
		{
			return _end_of_storage - _start;
		}
		size_t size()const
		{
			return _finish - _start;
		}
		void push_back(const T& x)
		{
			//扩容
			if (_finish == _end_of_storage)
			{
				reserve(capacity() == 0 ? 4 : capacity() * 2);
			}
			*_finish = x;
			++_finish;
		}
		T& operator[](size_t i)
		{
			assert(i < size());
			return _start[i];
		}
		const T& operator[](size_t i) const
		{
			assert(i < size());
			return _start[i];
		}
		bool empty()
		{
			return _start == _finish;
		}
		void pop_back()
		{
			assert(!empty());
			--_finish;
		}
		iterator insert(iterator pos, const T& x)  //这里pos前面不能加&  传过来的是临时变量的时候，具有常性，就不能用了
		{
			//扩容
			if (_finish == _end_of_storage)
			{
				size_t len = pos - _start;
				reserve(capacity() == 0 ? 4 : capacity() * 2);
				pos = _start + len;
			}
			iterator end = _finish - 1;
			while (end >= pos)
			{
				*(end + 1) = *end;
				end--;
			}
			*pos = x;
			++_finish;
			return pos;   
		}
	private:
		iterator _start = nullptr;
		iterator _finish = nullptr;
		iterator _end_of_storage = nullptr;

	};
	/*void Print_Vector(const vector<int>& v)
	{
		for (size_t i = 0; i < v.size(); i++)
		{
			cout << v[i] << " ";
		}
		cout << endl;
		vector<int>::const_iterator it = v.begin();
		while (it != v.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;

		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;
	}*/
	template<class T>
	void Print_Vector(const vector<T>& v)
	{
		for (size_t i = 0; i < v.size(); i++)
		{
			cout << v[i] << " ";
		}
		cout << endl;

		//在没有实例化的类模板里取东西的时候
		//编译器不知道这里的const_iterator是类型还是静态成员变量
		//这里加上typename是在告诉编译器这里是一个类型
		//typename vector<T>::const_iterator it = v.begin();
		auto it = v.begin();
		while (it != v.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;

		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;
	}
	void test1()
	{
		vector<int> v1;
		v1.push_back(1);
		v1.push_back(2);
		v1.push_back(3);
		v1.push_back(4);
		v1.push_back(5);
		Print_Vector(v1);
		vector<double> v2;
		v2.push_back(1.1);
		v2.push_back(2.2);
		v2.push_back(3.3);
	
		Print_Vector(v2);
		v2.insert(v2.begin(), 10.2);
		Print_Vector(v2);
		int x;
		cin >> x;
		auto pos = find(v1.begin(), v1.end(), x);
		if (pos != v1.end())
		{
			//insert之后pos就失效了，不能使用
			pos=v1.insert(pos, 30);
			//*pos *= 10; 
			pos = v1.insert(pos, 100);	//前面的insert加上返回值之后就可以先更新以下pos再访问
			*(pos + 2) *= 10;
		}
		Print_Vector(v1);

	}
}

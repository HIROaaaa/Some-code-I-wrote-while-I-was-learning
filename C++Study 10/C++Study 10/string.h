#pragma once
#include<iostream>
#include<assert.h>
using namespace std;
namespace hiro
{
	class string
	{
	public:
		string()
			:_str(new char[1]{'\0'})
			,_size(0)
			,_capacity(0)
		{ }
		string(const char* str)
		{
			_size = strlen(str);
			//capacity²»°üº¬ \0
			_capacity = _size;
			_str = new char[_capacity + 1];
			strcpy(_str, str);
		}
		size_t size()
		{
			return _size;
		}
		char* begin()
		{
			return _str;
		}
		char* end()
		{
			return _str + _size;
		}
		size_t size()const
		{
			return _size;
		}
		const char* begin()const
		{
			return _str;
		}
		const char* end()const
		{
			return _str + _size;
		}
		char& operator[](size_t pos)
		{
			assert(pos < _size);
			return _str[pos];
		}
		const char& operator[](size_t pos)const
		{
			assert(pos < _size);
			return _str[pos];
		}

		~string()
		{
			free(_str);
			_size = _capacity = 0;
		}
		
	private:
		char* _str;
		size_t _size;
		size_t _capacity;
	};
	void test_string1();
}
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;
class mystring
{
public:

	//s2(s1)
	void Swap(mystring& tmp)
	{
		std::swap(_str, tmp._str);			 //然后把tmp和要拷贝构造出来的str的所有内容交换
		std::swap(_size, tmp._size);          //如果_str不是空，那交换后tmp析构的时候会出问题
		std::swap(_capacity, tmp._capacity);
	}
	mystring(const mystring& s)  //还可以这么写string的拷贝构造
	{
		mystring tmp(s._str);    //这里直接用s来构造tmp       
		Swap(tmp);
	}
	//s1=s3
	mystring& operator=(const mystring& s)
	{
		if (this != &s)
		{
			mystring tmp(s._str);      //赋值也可以用这种方法写 
			Swap(tmp);				   //这里不需要delete[]_str
									   //交换后tmp会调用析构函数直接销毁
		}
		return *this;
	}
	//还可以这么写
	mystring& operator=(mystring tmp)//这里直接拷贝构造一个tmp
	{					//自己给自己赋值不用判断了
		Swap(tmp);				   
		return *this;
	}
private:
	char* _str=nullptr;  //这里一定要给缺省值，让_str为空
	int _size;
	int _capacity;
};
int main()
{
	char16_t str16[] = u"你好世界";  //想要用UTF16编码来存储要在字符串前面加一个u   //每个字符都是2个字节
	char32_t str32[] = U"你好世界";  //UTF32加U               //每个字符都是4个字节
	char str[] = "你好世界";
	str[0]--;  //这里是在对str第一个字符的编码进行-1
	cout << str << endl;

	wchar_t wstr[] = L"你好世界";    //wchar一般是做windows平台的开发会用到
									 //和UTF16差不多，都是两个字节 
									 //前面要加L
	return 0;
}
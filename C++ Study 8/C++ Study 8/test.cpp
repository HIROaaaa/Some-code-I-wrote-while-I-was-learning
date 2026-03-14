#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;
//class string   //operator[]大概就是这样
//{
//public:
//	char& operator[](size_t i)
//	{
//		assert(i<_size)
//		return _str[i];   //这里返回第i个字符的引用，就可以用类似 s5[3] = 'x'; 来改变第i个位置的字符
//	}
//private:
//	char* _str;
//	size_t _size;
//	size_t _capacity;
//};
int main()
{
	string s1;
	string s2("hello world");
	string s3(s2);
	cout << s1 << endl;
	cout << s2 << endl;
	cout << s3 << endl;
	string s4(s2, 6, 5);//从第n个位置拷贝m个字符
	cout << s4 << endl;
	string s5(s2, 6, 15);//这样会直接拷贝到最后，不会报错
	string s6(s2, 6 /*,nops*/ );//这里会直接相当于传npos，npos=-1 但是size_t类型是无符号的
	                            //所以这里会直接给最大值42亿多，也就相当于直接拷贝到最后
	string s7("hello world", 5); //拷贝前n个字符
	string s8(10, 'X');//拷贝n个字符到字符串中，这里必须是  ''
	cout << s7 << endl;
	cout << s8 << endl;
	s5[3] = 'x';   //和数组一样改变字符串第i个位置的字符, 越界了还会直接报错
	cout << s5 << endl;
	for (int i = 0; i < s2.size(); i++)   //string中提供了一个size接口来获得字符串的从长度
	{
		cout << s2[i] << " ";        //这种方法只有底层是数组的时候可以，其他类型的时候就要用迭代器了
	}
	cout << endl;
	
	//必须指明类域
	string::iterator it = s2.begin();   //这里用了迭代器，it可以看作是一个指针，  
										//如果it不是指针，这里的运算符也可以用运算符重载来进行操作
	while (it != s2.end())//这里的end()返回的是 past the end ，就是end的下一个位置
	{
		*it += 2;//迭代器这里可以修改s2里的字符
		cout << *it << " ";
		it++;
	}
	cout << endl;
	
	//遍历的另一种方法
	//范围for   这个适用于数组和容器
	for (auto ch : s2)  //这里的auto是自动推导，就是自动推导这里需要的类型
						//这里可以写成 char chr:s2
						//底层就是迭代器，这里编译的时候会变成上面迭代器的样子
						//但是上面的迭代器可以修改，这里的ch只是拷贝
	{
		ch-=2;				//这里只能修改ch的值，s2不会变
		cout << ch << " ";
	}
	cout << endl;

	cout << s2 << endl;
	
	for (auto& ch : s2)  //想要修改的话需要把这里改成引用，这里ch就变成了s2里每个字符的引用 

	{
		ch-=2;				
		cout << ch << " ";
	}
	cout << endl;

	int a = 0;
	cout << typeid(s2).name() << endl;  //typeid可以用来看类型
	cout << typeid(a).name() << endl; 


	//auto e;   //必须有初值，auto是通过右边的初值来推导类型的
	//auto a = 1, b = 1.1;            //这样会报错，必须是同一种类型
	//auto a[]={4,5,6}          //不能用来定义数组
	//int func1(auto a)            //不能做参数
	//auto func2(int a)         // 但是可以做返回值


	//反向迭代器   就是把迭代器全都倒过来了
	string::reverse_iterator rit = s2.rbegin();
	while (rit != s2.rend())
	{
		cout << *rit << " ";
		rit++;  //++也会倒着走   
	}
	cout << endl;



	const string s9("hello world");  //这里是const  auto会调用最匹配的  也就是const迭代器
	
	//const迭代器      //只能读不能写    cit指向的内容不能被修改    
	//string::const_iterator cit = s9.begin();
	auto cit = s9.begin();

	while (cit != s9.end())
	{
		cout << *cit << " ";
		cit++;  
	}
	cout << endl;

	//const反向迭代器
	//string::const_reverse_iterator crit = s9.rbegin();
	auto crit = s9.rbegin();

	while (crit != s9.rend())
	{
		cout << *crit << " ";
		crit++;
	}
	cout << endl;



	//string的长度/数据个数
	cout << s2.size() << endl;
	cout << s2.length() << endl;

	cout << s2.max_size() << endl;//string最大能开多长
	cout << s2.capacity() << endl;//有效空间

	s1.reserve(100); //预留n个字节的空间    大小不包含'\0'

	s1.reserve(10);     //这里会不会再缩小空间不一定，但是对内容肯定不会有影响   
						//也就是不会缩的比size还小
						//vs这里不会缩小    linux里的g++会缩小
	cout << s1.empty() << endl;
	s1.shrink_to_fit();   //会把多余的内存还给系统



	return 0;
}

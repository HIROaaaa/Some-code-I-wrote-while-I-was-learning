#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<vector>
using namespace std;
vector<vector<int>> generate(int numRows) {   //创建一个杨辉三角
	vector<vector<int>> vv(numRows);
	for (int i = 0; i < vv.size(); ++i)
	{
		vv[i].resize(i + 1, 1);
	}
	for (int i = 2; i < vv.size(); ++i)
	{
		for (int j = 1; j < vv[i].size() - 1; ++j)
		{
			vv[i][j] = vv[i - 1][j] + vv[i - 1][j - 1];
		}
	}
	return vv;
}
void TestVectorExpand()
{
	size_t sz;
	vector<int> v;
	sz = v.capacity();
	cout << "making v grow:\n";
	for (int i = 0; i < 100; ++i)
	{
		v.push_back(i);
		if (sz != v.capacity())
		{
			sz = v.capacity();
			cout << "capacity changed: " << sz << '\n';
		}
	}
}
void vector_test1()
{
	vector<int> v1;  //顺序表的初始化
	vector<int> v2(10,1);      //给10个1
	vector<int> v3(++v2.begin(),--v2.end());   //用v2的数据来初始化
	for (size_t i = 0; i < v3.size(); i++)
	{
		cout << v3[i] << " ";
	}
	cout << endl;
	vector<int>::iterator it = v3.begin();
	while(it != v3.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
	for (auto a : v3)
	{
		cout << a<<" ";
	}
	cout << endl;
}
void vector_test2()
{
	vector<int> v1(10, 1);
	v1.reserve(20);
	cout << v1.capacity() << endl;    
	cout << v1.size() << endl;
	v1.reserve(15);
	cout << v1.capacity() << endl;
	cout << v1.size() << endl;
	v1.reserve(5);
	cout << v1.capacity() << endl;    //不会缩容
	cout << v1.size() << endl;
	cout << endl;

	v1.resize(20);
	cout << v1.capacity() << endl;
	cout << v1.size() << endl;
	v1.resize(15);
	cout << v1.capacity() << endl;
	cout << v1.size() << endl;
	v1.resize(5);
	cout << v1.capacity() << endl;    //不会缩容但是会改变size 
	cout << v1.size() << endl;		//数据多的话会删除数据
}
void vector_test3()
{
	vector<int> v(10, 1);
	//v.push_back(5);
	//v.insert(v.begin(), 2);  //必须用迭代器的形式
	//for (auto e : v)
	//{
	//	cout << e << " ";
	//}
	//cout << endl;
	//v.insert(v.begin() + 3, 10);   //可以直接这样来在某个位置插入
	//for (auto e : v)
	//{
	//	cout << e << " ";
	//}
	//cout << endl;
	//vector<string> v2;       //还可以用vector存储其他的自定义类型
	//string s1("xxxx");
	//v2.push_back(s1);
	//v2.push_back("yyyy");
	//for (const auto& e : v)  //这里不加引用的话要多次拷贝构造
	//{
	//	cout << e << " ";
	//}
	//cout << endl;
	//cout << endl;
	vector<vector<int>> vv(5, v);  //相当于二维数组   一个10行5列的vector
	vv[1][2] = 3;
	vv.operator[](1).operator[](2) = 3;  //上面的实际上是这样的代码   
										 //operator传的是引用，这样才能对内容进行访问
	for (auto ee : vv)
	{
		for (auto e : ee)
		{
			cout << e << " ";
		}
		cout << endl;
	}
	cout << endl;
	cout << endl;
}
int main()
{
	//TestVectorExpand();  //这里可以看出来vs下的vector是1.5倍扩容，和string一样
	//vector_test1();
	vector_test3();
	return 0;
}
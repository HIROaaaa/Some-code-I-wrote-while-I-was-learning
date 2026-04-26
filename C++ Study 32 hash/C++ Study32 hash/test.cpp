#include<string>
using namespace std;

#include"HashTable.h"
struct StringHashFunc
{
	size_t operator()(const string& s)
	{
		size_t hash = 0;
		for (auto ch : s)
		{
			hash += ch;
		}
		return hash;
	}
};
#include <iostream>
#include "UnorderedSet.h"
#include "UnorderedMap.h"
using namespace std;
using namespace hiro;
void const_test_set(const unordered_set<int>& s)
{
	for (auto e : s)
	{
		cout << e << " ";
	}
	cout << endl;

	unordered_set<int>::const_iterator it = s.begin();
	while (it != s.end())
	{

		cout << *it << " ";
		++it;
	}
	cout << endl;
}
void test_set()
{
	unordered_set<int> s;
	int a[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14, 3,3,15 };
	for (auto e : a)
	{
		s.insert(e);
	}

	for (auto e : s)
	{
		cout << e << " ";
	}
	cout << endl;

	unordered_set<int>::iterator it = s.begin();
	while (it != s.end())
	{
		// 不⽀持修改
			//*it += 1;

		cout << *it << " ";
		++it;
	}
	cout << endl;
	const_test_set(s);
}
void test_map()
{
	unordered_map<string, string> dict;
	dict.insert({ "sort","排序" });
	dict.insert({ "字符串","string" });
	for (auto& kv : dict)
	{
		cout << kv.first << ":" << kv.second << endl;
	}
	cout << endl;
}
void test_map1()
{
	unordered_map<string, string> dict;
	dict.insert({ "sort", "排序" });
	dict.insert({ "left", "左边" });
	dict.insert({ "right", "右边" });

	dict["left"] = "左边，剩余";
	dict["insert"] = "插入";
	dict["string"];

	unordered_map<string, string>::iterator it = dict.begin();
	while (it != dict.end())
	{
		// 不能修改first，可以修改second
			//it->first += 'x';
		it->second += 'x';

		cout << it->first << ":" << it->second << endl;
		++it;
	}
	cout << endl;
}
int main()
{
	//test_set();
	test_map1();
	return 0;
}

#define _CRT_SECURE_NO_WARNINGS
#include"BinarySearch.h"
#include<string>
using namespace key_value;
int main()
{
	BSTree<string, string> dict;
	//BSTree<string, string> copy = dict;
	dict.Insert("left", "左边");
	dict.Insert("right", "右边");
	dict.Insert("insert", "插入");
	dict.Insert("string", "字符串");

	string str;
	while (cin >> str)
	{
		auto ret = dict.Find(str);
		if (ret)
		{
			cout << "->" << ret->_value << endl;
		}
		else
		{
			cout << "无此单词，请重新输入" << endl;
		}
	}

	return 0;
}

//int main()
//{
//	string arr[] = { "苹果", "西瓜", "苹果", "西瓜", "苹果", "苹果", "西瓜", "苹
//   果", "香蕉", "苹果", "香蕉" };
//	BSTree<string, int> countTree;
//	for (const auto& str : arr)
//	{
//		// 先查找水果在不在搜索树中
//		// 1、不在，说明⽔果第⼀次出现，则插入<水果, 1>
//		// 2、在，则查找到的结点中⽔果对应的次数++
//		//BSTreeNode<string, int>* ret = countTree.Find(str);
//		auto ret = countTree.Find(str);
//		if (ret == NULL)
//		{
//		countTree.Insert(str, 1);
//		}
//		else
//		{
//		ret->_value++;
//		}
//		}
//
//		countTree.InOrder();
//
//		return 0;
//	}
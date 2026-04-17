#include<iostream>

using namespace std;
#include"RBTree.h"
int main()
{
	RBTree<int, int> tree;
	tree.Insert({ 1,1 });
	tree.Insert({ 2,2 });
	tree.Insert({ 3,3 });
	tree.Insert({ 4,4 });
	tree.Insert({ 5,5 });
	tree.Insert({ 6,6 });

	cout << tree.IsBlance() << endl; // 输出 1 表示红黑树正确
	return 0;
}
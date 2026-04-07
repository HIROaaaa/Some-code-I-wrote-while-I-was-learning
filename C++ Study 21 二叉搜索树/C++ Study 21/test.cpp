#define _CRT_SECURE_NO_WARNINGS
#include"BinarySearch.h"
int main()
{
    BSTree<int> t;

    // 插入数据
    t.Insert(5);
    t.Insert(3);
    t.Insert(7);
    t.Insert(2);
    t.Insert(4);
    t.Insert(6);
    t.Insert(8);

    // 中序遍历输出（一定是升序）
    cout << "中序遍历结果：";
    t.InOrder();

	return 0;
}
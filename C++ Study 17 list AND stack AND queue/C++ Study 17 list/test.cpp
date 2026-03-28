#define _CRT_SECURE_NO_WARNINGS
//#include"list.h"

//#include<queue>
#include<vector>
#include<list>

using namespace std;
#include"Stack.h"
#include"Queue"
using namespace hiro;

void test()
{
	stack<int, vector<int>> st;
	st.push(1);
	st.push(2);
	st.push(3);
	st.push(4);
}
void test2()
{
	queue<int, vector<int>> st; //vector其实不支持头删  ，这里不会报错是因为没有使用
	st.push(1);
	st.push(2);
	st.push(3);
	st.push(4);
	//st.pop();
}
//最小栈   找栈里的最小值，用0(1)的时间复杂度
class MinStack {
public:

	void push(int val) {
		_st.push(val);
		if (_minst.empty() || _minst.top() >= val)
		{
			_minst.push(val);
		}
	}

	void pop() {
		if (_minst.top() == _st.top())
		{
			_minst.pop();
		}
		_st.pop();
	}

	int top() {
		return _st.top();
	}

	int getMin() {
		return _minst.top();
	}
private:
	stack<int> _st;
	stack<int> _minst;
};

//栈的压入、弹出序列    判断一个顺序是不是对的
class Solution1 {
public:
	/**
	 * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
	 *
	 *
	 * @param pushV int整型vector
	 * @param popV int整型vector
	 * @return bool布尔型
	 */
	bool IsPopOrder(vector<int>& pushV, vector<int>& popV) {
		int popi = 0;
		stack<int> st;
		for (auto& e : pushV)
		{
			st.push(e);
			while (!st.empty() && st.top() == popV[popi])
			{
				st.pop();
				++popi;
			}
		}
		return st.empty();
	}
};
//二叉树的层序遍历
struct TreeNode
{					//假设一个树
	int val;
	TreeNode* left;
	TreeNode* right;
};
class Solution {
public:
	vector<vector<int>> levelOrder(TreeNode* root)
	{
		vector<vector<int>> vv;
		queue<TreeNode*> q;
		int levelSize = 0;
		if (root)
		{
			q.push(root);
			levelSize = 1;
		}
		while (!q.empty())
		{
			vector<int> v;
			while (levelSize--)
			{
				TreeNode* front = q.front();
				v.push_back(front->val);
				q.pop();
				if (front->left)
				{
					q.push(front->left);
				}
				if (front->right)
				{
					q.push(front->right);
				}
			}
			vv.push_back(v);
			levelSize = q.size();
		}
		return vv;
	}
};

int main()
{
	test();
	test2();
	//hiro::test2();
	return 0;
}
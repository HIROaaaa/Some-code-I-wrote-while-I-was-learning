#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;
struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		string v1;
		string v2;
		while (l1)
		{
			v1 += (l1->val + '0');
			l1 = l1->next;
		}
		while (l2)
		{
			v2 += (l2->val + '0');
			l2 = l2->next;
		}
		string tmp;
		int begin1 = 0, begin2 = 0;
		int next = 0;
		while (begin1 < v1.size() || begin2 < v2.size())
		{
			int num1 = (begin1 < v1.size() ? v1[begin1++] - '0' : 0);
			int num2 = (begin2 < v2.size() ? v2[begin2++] - '0' : 0);
			int ret = num1 + num2 + next;
			next = ret / 10;
			ret = ret % 10;
			tmp += (ret + '0');
		}
		if (next)
		{
			tmp += next + '0';
		}
		ListNode* dummyHead = new ListNode(0);
		ListNode* head = dummyHead;
		for (auto e : tmp)
		{
			head->next = new ListNode(e - '0');
			head = head->next;
		}
		ListNode* ret = dummyHead->next;
		delete dummyHead;
		return ret;
	}
};
int main()
{
	ListNode* l1= new ListNode(1);
	ListNode* l3 = l1;
	l1->next = new ListNode(1);
	l1 = l1->next;
	l1->next = new ListNode(2);
	l1 = l1->next;
	l1->next = new ListNode(3);
	l1 = l1->next;
	l1->next = new ListNode(4);
	l1 = l1->next;
	ListNode* l2 = new ListNode(1);
	ListNode* l4 = l2;
	l2->next = new ListNode(1);
	l2 = l2->next;
	l2->next = new ListNode(2);
	l2 = l2->next;
	l2->next = new ListNode(3);
	l2 = l2->next;
	l2->next = new ListNode(4);
	l2 = l2->next;
	
	Solution so1;
	ListNode* ret=so1.Solution::addTwoNumbers(l3, l4);
	while (ret)
	{
		cout << ret->val;
		ret = ret->next;
	}
	cout << endl;
	return 0;
}
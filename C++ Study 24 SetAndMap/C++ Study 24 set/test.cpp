#include<iostream>
#include<set>
#include<map>
#pragma execution_character_set("utf-8")
using namespace std;




void test_set()
{
	multiset<int> s1({ 1,2,3,1,3,2,2,41,13,1,41,3,13, });
	auto its = s1.begin();
	while (its != s1.end())
	{
		cout << *its << " ";
		++its;
	}
	cout << endl;
	s1.erase(1);
	its = s1.begin();
	while (its != s1.end())
	{
		cout << *its << " ";
		++its;
	}
	cout << endl;
}
void test_map()
{
	//map<string, string> m1;
	map<string, string> m1 = { {"left", "左边"}, {"right", "右边"},
{"insert", "插⼊"},{ "string", "字符串" } };
	pair<string, string>pa1("first", "第一个");
	m1.insert(pa1);
	m1.insert(pair<string, string>("second", "第二个"));
	m1.insert(make_pair("minecraft", "我的世界"));
	m1.insert({ "star","星星" });
	map<string, string>::iterator it = m1.begin();
	while (it != m1.end())
	{
		cout << it->first << ":" << it->second << endl;
		++it;
	}
}
int main()
{
	//test_set();
	test_map();
	return 0;
}




//随机链表的复制
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};


class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* cur = head;
        Node* copyhead = nullptr, * copytail = nullptr;
        map<Node*, Node*> copymap;
        while (cur)//拷贝原链表
        {
            if (copytail == nullptr)   //目前拷贝出来的链表是空
            {
                copyhead = copytail = new Node(cur->val);
            }
            else
            {
                copytail->next = new Node(cur->val);
                copytail = copytail->next;
            }
            copymap[cur] = copytail;  //建立原结点和新节点之间的映射
            cur = cur->next;
        }
        cur = head;
        Node* copy = copyhead;
        while (cur)  //处理random指针
        {
            if (cur->random == nullptr)
            {
                copy->random = nullptr;
            }
            else
            {
                copy->random = copymap[cur->random];
            }
            copy = copy->next;
            cur = cur->next;
        }
        return copyhead;
    }
};
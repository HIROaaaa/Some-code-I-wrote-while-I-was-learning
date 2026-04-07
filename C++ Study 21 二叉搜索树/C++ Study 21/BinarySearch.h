#pragma once
#include<iostream>
using namespace std;
template <class K>
struct BSTNode
{
	K _key;
	BSTNode<K>* _left;
	BSTNode<K>* _right;

	BSTNode(const K& key)
		:_key(key)
		, _left(nullptr)
		, _right(nullptr)
	{
	}
};
template <class K>
class BSTree
{
	using Node = BSTNode<K>;
public:
	bool Insert(const K& x)
	{
		if (_root == nullptr)
		{
			_root = new Node(x);
		}
		Node* parent=nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (cur->_key < x)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (cur->_key > x)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				return false;
			}
		}
		cur = new Node(x);
		if (parent->_key < x)
		{
			parent->_right = cur;
		}
		else
		{
			parent->_left = cur;
		}
		return true;
	}
	bool Find(const K& key)
	{
		Node* cur = _root;
		while (cur)
		{
			if (cur->_key < key)
			{
				cur = cur->_right;
			}
			else if (cur->_key > key)
			{
				cur = cur->_left;
			}
			else
			{
				return true;
			}
		}
		return false;
	}
	void InOrder()
	{
		_InOrder(_root);
		cout << endl;
	}
private:
	void _InOrder(Node* root)
	{
		if (root == nullptr)
		{
			return;
		}
		_InOrder(root->_left);
		cout << root->_key << " ";
		_InOrder(root->_right);
	}
	Node* _root = nullptr;
};

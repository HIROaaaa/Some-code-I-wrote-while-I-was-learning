#pragma once
#include<iostream>
using namespace std;
namespace key
{
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
				return true;
			}
			Node* parent = nullptr;
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
		bool Erase(const K& key)
		{
			Node* parent = nullptr;
			Node* cur = _root;
			while (cur)
			{
				if (cur->_key < key)
				{
					parent = cur;
					cur = cur->_right;
				}
				else if (cur->_key > key)
				{
					parent = cur;
					cur = cur->_left;
				}
				else
				{
					//删除
					if (cur->_left == nullptr)
					{
						if (cur == _root)
						{
							_root = cur->_right;
						}
						else
						{
							if (cur == parent->_left)
							{
								parent->_left = cur->_right;
							}
							else
							{
								parent->_right = cur->_right;
							}

						}
						delete cur;
						return true;
					}
					else if (cur->_right == nullptr)
					{
						if (cur == _root)
						{
							_root = cur->_left;
						}
						else
						{
							if (cur == parent->_left)
							{
								parent->_left = cur->_left;
							}
							else
							{
								parent->_right = cur->_left;
							}

						}
						delete cur;
						return true;
					}
					else
					{
						Node* replaceParent = cur;
						Node* replace = cur->_right;
						while (replace->_left)
						{
							replaceParent = replace;
							replace = replace->_left;
						}
						cur->_key = replace->_key;
						if (replaceParent->_left == replace)
						{
							replaceParent->_left = replace->_right;
						}
						else
						{
							replaceParent->_right = replace->_right;
						}
						delete replace;
						return true;
					}
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
}
namespace key_value
{
	template <class K, class V>
	struct BSTNode
	{
		K _key;
		V _value;
		BSTNode<K, V>* _left;
		BSTNode<K, V>* _right;

		BSTNode(const K& key, const V& value)
			:_key(key)
			, _value(value)
			, _left(nullptr)
			, _right(nullptr)
		{
		}
	};
	template <class K, class V>
	class BSTree
	{
		using Node = BSTNode<K, V>;
	public:
		//强制生成默认构造
		BSTree() = default;
		BSTree(const BSTree& t)
		{
			_root = Copy(t._root);
		}
		~BSTree()
		{
			Destroy(_root);
			_root = nullptr;
		}
		BSTree& operator=(BSTree tmp)
		{
			swap(_root, tmp._root);
			return *this;
		}
		bool Insert(const K& key, const V& val)
		{
			if (_root == nullptr)
			{
				_root = new Node(key, val);
				return true;
			}
			Node* parent = nullptr;
			Node* cur = _root;
			while (cur)
			{
				if (cur->_key < key)
				{
					parent = cur;
					cur = cur->_right;
				}
				else if (cur->_key > key)
				{
					parent = cur;
					cur = cur->_left;
				}
				else
				{
					return false;
				}
			}
			cur = new Node(key, val);
			if (parent->_key < key)
			{
				parent->_right = cur;
			}
			else
			{
				parent->_left = cur;
			}
			return true;
		}
		Node* Find(const K& key)
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
					return cur;
				}
			}
			return nullptr;
		}
		bool Erase(const K& key)
		{
			Node* parent = nullptr;
			Node* cur = _root;
			while (cur)
			{
				if (cur->_key < key)
				{
					parent = cur;
					cur = cur->_right;
				}
				else if (cur->_key > key)
				{
					parent = cur;
					cur = cur->_left;
				}
				else
				{
					//删除
					if (cur->_left == nullptr)
					{
						if (cur == _root)
						{
							_root = cur->_right;
						}
						else
						{
							if (cur == parent->_left)
							{
								parent->_left = cur->_right;
							}
							else
							{
								parent->_right = cur->_right;
							}

						}
						delete cur;
						return true;
					}
					else if (cur->_right == nullptr)
					{
						if (cur == _root)
						{
							_root = cur->_left;
						}
						else
						{
							if (cur == parent->_left)
							{
								parent->_left = cur->_left;
							}
							else
							{
								parent->_right = cur->_left;
							}

						}
						delete cur;
						return true;
					}
					else
					{
						Node* replaceParent = cur;
						Node* replace = cur->_right;
						while (replace->_left)
						{
							replaceParent = replace;
							replace = replace->_left;
						}
						cur->_key = replace->_key;
						cur->_value = replace->_value;
						if (replaceParent->_left == replace)
						{
							replaceParent->_left = replace->_right;
						}
						else
						{
							replaceParent->_right = replace->_right;
						}
						delete replace;
						return true;
					}
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
		Node* Copy(Node* root)
		{
			if (root == nullptr)
				return nullptr;

			Node* newRoot = new Node(root->_key, root->_value);
			newRoot->_left = Copy(root->_left);
			newRoot->_right = Copy(root->_right);

			return newRoot;
		}
		void _InOrder(Node* root)
		{
			if (root == nullptr)
			{
				return;
			}
			_InOrder(root->_left);
			cout << root->_key << ":" << root->_value << " ";
			_InOrder(root->_right);
		}
		void Destroy(Node* root)
		{
			if (root == nullptr)
				return;

			Destroy(root->_left);
			Destroy(root->_right);
			delete root;
		}
		Node* _root = nullptr;
	};
}

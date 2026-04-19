#pragma once

enum Colour
{
	RED,
	BLACK
};


template <class T>
struct RBTreeNode
{

	T _data;
	RBTreeNode<T>* _left;
	RBTreeNode<T>* _right;
	RBTreeNode<T>* _parent;
	Colour _col;

	RBTreeNode(const T& data)
		: _data(data)
		, _left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _col(RED)
	{
	}
};

template <class T, class Ref, class Ptr>
struct RBTreeIterator
{
	typedef RBTreeNode<T> Node;
	typedef RBTreeIterator<T, Ref, Ptr> Self;
	Node* _node;

	RBTreeIterator(Node* node)
		:_node(node)
	{
	}
	Self operator++()
	{
		//右不为空，下一个访问的结点是右子树最左（最小）节点
		if (_node->_right)
		{
			Node* min = _node->_right;
			while (min->_left)
			{
				min = min->_left;
			}
			_node = min;
		}
		else
		{
			//右为空，访问孩子是父亲左的祖先
			Node* cur = _node;
			Node* parent = cur->_parent;
			while (parent/*走到根节点的时候parent为空*/ && cur == parent->_right)
			{
				cur = parent;
				parent = cur->_parent;
			}
			_node = parent;
		}
		return *this;
	}

	Self& operator--()
	{
		if (_node->_left)
		{
			// 左子树不为空，中序左子树最后一个
			Node* rightMost = _node->_left;
			while (rightMost->_right)
			{
				rightMost = rightMost->_right;
			}
			_node = rightMost;
		}
		else
		{
			// 孩子是父亲右的那个祖先
			Node* cur = _node;
			Node* parent = cur->_parent;
			while (parent && cur == parent->_left)
			{
				cur = parent;
				parent = cur->_parent;
			}
			_node = parent;
		}
		return *this;
	}

	Ref operator*()
	{
		return _node->_data;
	}

	Ptr operator->()
	{
		return &_node->_data;
	}
	bool operator!= (const Self& s)
	{
		return _node != s._node;
	}

	bool operator== (const Self& s)
	{
		return _node == s._node;
	}
	bool operator!= (const Self& s) const
	{
		return _node != s._node;
	}

	bool operator== (const Self& s) const
	{
		return _node == s._node;
	}
};

template <class K, class T, class KeyOfT>
class RBTree
{
	typedef RBTreeNode<T> Node;
public:
	typedef typename RBTreeIterator<T, T&, T*> Iterator;
	typedef typename RBTreeIterator<T, const T&, const T*> ConstIterator;

	Iterator Begin()
	{
		Node* cur = _root;
		while (cur && cur->_left != nullptr)
		{
			cur = cur->_left;
		}
		return Iterator(cur);
	}

	Iterator End()
	{
		return Iterator(nullptr);
	}
	ConstIterator Begin()const
	{
		Node* cur = _root;
		while (cur && cur->_left != nullptr)
		{
			cur = cur->_left;
		}
		return ConstIterator(cur);
	}

	ConstIterator End()const
	{
		return ConstIterator(nullptr);
	}
	void RotateR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;
		parent->_left = subLR;
		if (subLR)
		{
			subLR->_parent = parent;
		}
		Node* parentParent = parent->_parent;

		subL->_right = parent;
		parent->_parent = subL;
		if (parentParent == nullptr)
		{
			_root = subL;
			subL->_parent = nullptr;
		}
		else
		{
			if (parent == parentParent->_left)
			{
				parentParent->_left = subL;
			}
			else
			{
				parentParent->_right = subL;
			}
			subL->_parent = parentParent;
		}
	}
	void RotateL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;
		parent->_right = subRL;
		if (subRL)
		{
			subRL->_parent = parent;
		}

		Node* parentParent = parent->_parent;

		subR->_left = parent;
		parent->_parent = subR;

		if (parentParent == nullptr)
		{
			_root = subR;
			subR->_parent = nullptr;
		}
		else
		{
			if (parentParent->_left == parent)
			{
				parentParent->_left = subR;
			}
			else
			{
				parentParent->_right = subR;
			}
			subR->_parent = parentParent;
		}
	}
	bool Insert(const T& data)
	{
		if (_root == nullptr)
		{
			_root = new Node(data);
			_root->_col = BLACK;
			return true;
		}
		//找到该插入的位置
		KeyOfT kot;
		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (kot(cur->_data) < kot(data))
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (kot(cur->_data) > kot(data))
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				return false;
			}
		}
		cur = new Node(data);
		cur->_col = RED;
		if (kot(parent->_data) < kot(data))
		{
			parent->_right = cur;
		}
		else
		{
			parent->_left = cur;
		}
		//链接父亲
		cur->_parent = parent;
		while (parent && parent->_col == RED)
		{
			Node* grandparent = parent->_parent;
			if (parent == grandparent->_left)
			{
				Node* uncle = grandparent->_right;
				if (uncle && uncle->_col == RED)
				{
					parent->_col = uncle->_col = BLACK;
					grandparent->_col = RED;
					cur = grandparent;
					parent = cur->_parent;
				}
				else
				{
					if (cur == parent->_left)
					{
						RotateR(grandparent);
						parent->_col = BLACK;
						grandparent->_col = RED;

					}
					else
					{
						RotateL(parent);
						RotateR(grandparent);
						cur->_col = BLACK;
						grandparent->_col = RED;

					}
					break;
				}
			}
			else
			{
				Node* uncle = grandparent->_left;
				if (uncle && uncle->_col == RED)
				{
					parent->_col = uncle->_col = BLACK;
					grandparent->_col = RED;
					cur = grandparent;
					parent = cur->_parent;
				}
				else
				{
					if (cur == parent->_right)
					{
						RotateL(grandparent);
						parent->_col = BLACK;
						grandparent->_col = RED;

					}
					else
					{
						RotateR(parent);
						RotateL(grandparent);
						cur->_col = BLACK;
						grandparent->_col = RED;

					}
					break;
				}
			}
		}
		_root->_col = BLACK;
		return true;
	}
private:
	Node* _root = nullptr;
};
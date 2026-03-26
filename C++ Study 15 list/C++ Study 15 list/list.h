#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
namespace hiro
{
	template <class T>
	struct list_node
	{
		list_node(const T& data=T())
			:_data(data)
			,_next(nullptr)
			,_prev(nullptr)
		{}
		T _data;
		list_node<T>* _next;
		list_node<T>* _prev;
	};
	template<class T>
	struct list_iterator
	{
		typedef list_node<T> Node;
		typedef list_iterator<T> Self;
		Node* _node;
		list_iterator(Node * node)
			:_node(node)
		{}
		T& operator*()
		{
			return _node->_data;
		}
		Self& operator++()
		{
			_node = _node->_next;
			return *this;
		}
		Self& operator--()
		{
			_node = _node->_prev;
			return *this;
		}
		bool operator!=(const Self& s)
		{
			return _node != s._node;
		}
	};
	template <class T>
	class list
	{
		typedef list_node<T> Node;
	public:
		typedef list_iterator<T> iterator;
		list()
		{
			_head = new Node;
			_head->_next = _head;
			_head->_prev = _head;
			_size = 0;
		}
		iterator begin()
		{
			/*iterator it(_head->next);
			return it;*/
			return _head->_next;
		}
		iterator end()
		{
			/*iterator it(_head);
			return it;*/
			return _head;
		}
		/*void push_back(const T& x)
		{
			Node* newnode = new Node(x);
			Node* tail = _head->_prev;
			tail->_next = newnode;
			newnode->_next = _head;
			_head->_prev = newnode;
			newnode->_prev = tail;
			++_size;
		}*/
		void push_back(const T& x)
		{
			insert(end(), x);
		}
		void push_front(const T& x)
		{
			insert(begin(), x);
		}
		void insert(iterator pos,const T& x)
		{
			Node* cur = pos._node;
			Node* prev = cur->_prev;

			Node* newnode = new Node(x);
			prev->_next = newnode;
			newnode->_prev = prev;
			newnode->_next = cur;
			cur->_prev = newnode;
			++size;
		}
		void erase(iterator pos)
		{
			assert(pos!=end())
			Node* next = pos._node->_next;
			Node* prev = pos._node->_prev;
			
			prev->_next = next;
			next->_prev = prev;
			delete pos._node;
			--size;
		}
		void pop_back()
		{
			erase(--end());
		}
		void pop_front()
		{
			erase(begin());
		}
		size_t size()
		{
			return _size;
		}
		bool empty()
		{
			return _size == 0;
		}
	private:
		Node* _head;
		size_t _size;
	}; 
	void test1()
	{
		list<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);
		list<int>::iterator it = lt.begin();
		while (it != lt.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;
		for (auto e : lt)
		{
			cout << e << " ";
		}
		cout << endl;
	}
}

#include<iostream>
#include<cassert>
using namespace std;
namespace hiro
{
	template <class T>
	struct list_node
	{
		list_node(const T& data = T())
			:_data(data)
			, _next(nullptr)
			, _prev(nullptr)
		{
		}
		T _data;
		list_node<T>* _next;
		list_node<T>* _prev;
	};
	template<class T,class REF,class PTR>
	struct list_iterator
	{
		typedef list_node<T> Node;
		typedef list_iterator<T,REF,PTR> Self;
		Node* _node;
		list_iterator(Node* node)
			:_node(node)
		{
		}
		REF operator*()
		{
			return _node->_data;
		}
		Self& operator++()
		{
			_node = _node->_next;
			return *this;
		}
		Self& operator++(int)
		{
			Self tmp(*this);
			_node = _node->_next;
			return tmp;
		}
		Self& operator--()
		{
			_node = _node->_prev;
			return *this;
		}
		Self& operator--(int)
		{
			Self tmp(*this);
			_node = _node->_prev;
			return tmp;
		}
		bool operator!=(const Self& s)
		{
			return _node != s._node;
		}
		PTR operator->()
		{
			return &_node->_data;
		}
	};
	/*template<class T>
	struct const_list_iterator
	{
		typedef list_node<T> Node;
		typedef const_list_iterator<T> Self;
		Node* _node;
		const_list_iterator(Node* node)
			:_node(node)
		{}
		const T& operator*()const
		{
			return _node->_data;
		}
		Self& operator++()
		{
			_node = _node->_next;
			return *this;
		}
		Self& operator++(int)
		{
			Self tmp(*this);
			_node = _node->_next;
			return tmp;
		}
		Self& operator--()
		{
			_node = _node->_prev;
			return *this;
		}
		Self& operator--(int)
		{
			Self tmp(*this);
			_node = _node->_prev;
			return tmp;
		}
		bool operator!=(const Self& s)const
		{
			return _node != s._node;
		}
		const T* operator->()const
		{
			return &_node->_data;
		}
	};*/
	template <class T>
	class list
	{
		typedef list_node<T> Node;
	public:
		typedef list_iterator<T,T&,T*> iterator;
		typedef list_iterator<T,const T&,const T*> const_iterator;
		void empty_init()
		{
			_head = new Node;
			_head->_next = _head;
			_head->_prev = _head;
			_size = 0;
		}
		list()
		{
			empty_init();
		}
		list(initializer_list<T> il)
		{
			empty_init();
			for (auto e : il)
			{
				push_back(e);
			}
		}
		list(const list<T>& lt)
		{
			empty_init();
			for (auto e : lt)
			{
				push_back(e);
			}
		}
		void swap(list<T>& lt)
		{
			std::swap(_head, lt._head);
			std::swap(_size, lt._size);
		}
		list<T>&operator=(list<T>& lt)
		{
			swap(lt);
			return *this;
		}
		iterator begin()
		{
			/*iterator it(_head->next);
			return it;*/
			return _head->_next;
		}
		const_iterator end()const
		{
			/*iterator it(_head);
			return it;*/
			return _head;
		}
		const_iterator begin()const
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
		iterator insert(iterator pos, const T& x)
		{
			Node* cur = pos._node;
			Node* prev = cur->_prev;

			Node* newnode = new Node(x);
			prev->_next = newnode;
			newnode->_prev = prev;
			newnode->_next = cur;
			cur->_prev = newnode;
			++_size;
			return newnode;  //为了防止迭代器失效
		}
		iterator erase(iterator pos)
		{
			assert(pos != end());
			Node* next = pos._node->_next;
			Node* prev = pos._node->_prev;

			prev->_next = next;
			next->_prev = prev;
			delete pos._node;
			--_size;
			return next;//为了防止迭代器失效
		}
		void clear()
		{
			auto it = begin();
			while (it != end())
			{
				it = erase(it);
			}
		}
		~list()
		{
			clear();
			delete _head;
			_head = nullptr;
		}
		void pop_back()
		{
			erase(--end());
		}
		void pop_front()
		{
			erase(begin());
		}
		size_t size()const
		{
			return _size;
		}
		bool empty()const
		{
			return _size == 0;
		}
		
	private:
		Node* _head;
		size_t _size;
	};
	struct AA
	{
		int _a1 = 1;
		int _a2 = 2;
	};
	ostream& operator<<(ostream& out, const AA& aa)
	{
		out << aa._a1 << " " << aa._a2;
		return out;
	}
	template<class Container>
	void Print_Container(const Container& v)
	{
		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;
	}
	void test3(const list<int>& lt)
	{
		Print_Container(lt);
	}
	void test2()
	{
		list<int> lt1 = { 1,2,3,4,5,6,7,8 };

		//这里进行了隐式类型转换   
		//编译器会先将右侧的花括号列表隐式转换为std::initializer_list<int>
		list<int> lt2({1,2,3,4,5,6,7,8 });
		const list<int>& lt3({ 1,2,3,4,5,6,7,8 });  //const会把这个临时对象的声明周期延长
		test3({ 1,2,3,4,5,6,7 });
	}
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
		list<AA> lta;
		lta.push_back(AA());
		lta.push_back(AA());
		lta.push_back(AA());
		lta.push_back(AA());
		list<AA>::iterator ita = lta.begin();
		while (ita != lta.end())
		{
			cout << ita->_a1/*这里其实是应该是两个->  省略了一个*/ <<" " << ita->_a2 << endl;
			//cout << ita.operator->()->_a1 << ita->_a2 << endl;
			ita++;
		}
		cout << endl;
		Print_Container(lta);
	}
}

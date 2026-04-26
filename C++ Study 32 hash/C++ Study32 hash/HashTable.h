#pragma once
#include<vector>
#include<string>
using namespace std;
enum State
{
	EXIST,
	EMPTY,
	DELETE
};
template <class K, class V>
struct HashData
{
	pair<K, V> _kv;
	State _state = EMPTY;
};
template<class K>
struct HashFunc
{
	size_t operator()(const K& key)
	{

		return (size_t)key;
	}
};
//偏特化
template<>
struct HashFunc<string>
{
	size_t operator()(const string& s)
	{
		// 改用BKDR哈希，冲突率低，支持中文
		size_t hash = 0;
		for (auto ch : s)
		{
			hash = hash * 131 + ch;
		}
		return hash;
	}
};

inline unsigned long _stl_next_prime(unsigned long n)
{

	static const int __stl_num_primes = 28;
	static const unsigned long __stl_prime_list[__stl_num_primes] =
	{
	53, 97, 193, 389, 769,
		1543, 3079, 6151, 12289, 24593,
		49157, 98317, 196613, 393241, 786433,
		1572869, 3145739, 6291469, 12582917, 25165843,
		50331653, 100663319, 201326611, 402653189, 805306457,
		1610612741, 3221225473, 4294967291
	};
	for (int i = 0; i < __stl_num_primes; ++i)
	{
		if (__stl_prime_list[i] > n)
			return __stl_prime_list[i];
	}
	return __stl_prime_list[__stl_num_primes - 1];
}

namespace hash_bucket
{
	template <class T>
	struct HashNode
	{
		T _data;
		HashNode<T>* _next;

		HashNode(const T& data)
			:_data(data)
			, _next(nullptr)
		{
		}
	};

	template <class K, class T, class KeyOfT, class Hash>
	class HashTable;

	template<class K, class T, class Ref, class Ptr, class KeyOfT, class Hash>
	struct HTIterator
	{
		typedef HashNode<T> Node;
		typedef HashTable<K, T, KeyOfT, Hash> HT;
		typedef HTIterator<K, T, Ref, Ptr, KeyOfT, Hash> Self;
		Node* _node;
		const HT* _ht;
		HTIterator(Node* node,const HT* ht)
			:_node(node)
			, _ht(ht)

		{
		}
		Ref operator*()
		{
			return _node->_data;
		}
		Ptr operator->()
		{
			return &_node->_data;
		}
		bool operator!=(const Self& s)
		{
			return _node != s._node;
		}
		Self& operator++()
		{
			if (_node->_next)
			{
				_node = _node->_next;
			}
			else
			{
				KeyOfT kot;
				Hash hash;
				size_t hashi = hash(kot(_node->_data)) % _ht->_tables.size();
				++hashi;
				while (hashi < _ht->_tables.size())
				{
					_node = _ht->_tables[hashi];
					if (_node)
					{
						break;
					}
					else
					{
						++hashi;
					}
				}

				if (hashi == _ht->_tables.size())
				{
					_node = nullptr;
				}
			}
			return *this;
		}
	};

	template < class K, class T, class KeyOfT, class Hash = HashFunc<K>>
	class HashTable
	{
		template<class K, class T, class Ref, class Ptr, class KeyOfT, class Hash>
		friend struct HTIterator;
		typedef HashNode<T> Node;
	public:
		typedef HTIterator<K, T, T&, T*, KeyOfT, Hash> Iterator;
		typedef HTIterator<K, T, const T&, const T*, KeyOfT, Hash> ConstIterator;
		Iterator Begin()
		{
			if (_n == 0)
			{
				return End();
			}
			for (size_t i = 0;i < _tables.size();++i)
			{
				Node* cur = _tables[i];
				if (cur)
				{
					return Iterator(cur, this);
				}
			}
			return End();
		}
		Iterator End()
		{
			return Iterator(nullptr, this);
		}
		ConstIterator Begin() const
		{
			if (_n == 0)
			{
				return End();
			}
			for (size_t i = 0;i < _tables.size();++i)
			{
				Node* cur = _tables[i];
				if (cur)
				{
					return ConstIterator(cur, this);
				}
			}
			return End();
		}
		ConstIterator End()const
		{
			return ConstIterator(nullptr, this);
		}
		HashTable()
			:_tables(_stl_next_prime(0))
			, _n(0)
		{
		}

		~HashTable()
		{
			for (size_t i = 0; i < _tables.size(); ++i)
			{
				Node* cur = _tables[i];
				while (cur)
				{
					Node* next = cur->_next;
					delete cur;
					cur = next;
				}
				_tables[i] = nullptr;
			}
		}

		pair<Iterator,bool> Insert(const T& data)
		{
			KeyOfT kot;
			Hash hash;
			Iterator it = Find(kot(data));
			if (it!=End())
			{
				return {it,false};
			}
			//负载因子--1扩容
			if (_n == _tables.size())
			{
				vector<Node*> newTable(_stl_next_prime(_tables.size() + 1));
				for (size_t i = 0;i < _tables.size();i++)
				{
					//直接把旧表的数据移到新表，不是复制一份
					Node* cur = _tables[i];
					while (cur)
					{
						Node* next = cur->_next;
						size_t hashi = hash(kot(cur->_data)) % newTable.size();
						cur->_next = newTable[hashi];
						newTable[hashi] = cur;

						cur = next;
					}
					_tables[i] = nullptr;
				}
				_tables.swap(newTable);
			}
			size_t hashi = hash(kot(data)) % _tables.size();

			//头插
			Node* newnode = new Node(data);
			newnode->_next = _tables[hashi];
			_tables[hashi] = newnode;
			++_n;
			return {Iterator(newnode,this),true};
		}

		Iterator Find(const K& key)
		{
			KeyOfT kot;
			Hash hash;

			size_t hashi = hash(key) % _tables.size();
			Node* cur = _tables[hashi];
			while (cur)
			{
				if (kot(cur->_data) == key)
				{
					return Iterator(cur,this);
				}
				cur = cur->_next;
			}
			return End();
		}
		bool Erase(const K& key)
		{
			KeyOfT kot;
			Hash hash;
			size_t hashi = hash(key) % _tables.size();
			Node* prev = nullptr;
			Node* cur = _tables[hashi];
			while (cur)
			{
				if (kot(cur->_data) == key)
				{
					if (prev == nullptr)
					{
						//删除头节点
						_tables[hashi] = cur->_next;
					}
					else
					{
						prev->_next = cur->_next;
					}
					delete cur;
					--_n;
					return true;
				}
				else
				{
					prev = cur;
					cur = cur->_next;
				}
			}
			return false;
		}
	private:
		vector<Node*> _tables; // 指针数组
		size_t _n = 0; // 表中存储数据个数
	};
}
#pragma once
#include<vector>

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
		size_t hash = 0;
		for (auto ch : s)
		{
			hash += ch;
		}
		return hash;
	}
};
template <class K, class V,class Hash= HashFunc<K>>
class HashTable
{
public:
	HashTable()
		:_tables(11)
		, _n(0)
	{
	}
	bool Insert(const pair<K, V>& kv)
	{
		//扩容
		if (_n * 10 / _tables.size() >= 7)
		{
			//vector<HashData<K, V>> newtables(_tables.size() * 2);
			//for (auto& data : _tables)
			//{
			//	//旧表的数据映射到新表
			//	if (data._state == EXIST)
			//	{
			//		size_t hash0 = data._k.first % newtables.size();
			//	}
			//}
			//_tables.swap(newtables);

			HashTable<K, V, Hash> newht;
			newht._tables.resize(_tables.size() * 2);
			for (auto& data : _tables)
			{
				//旧表的数据映射到新表
				if (data._state == EXIST)
				{
					newht.Insert(data._kv);
				}
			}
			_tables.swap(newht._tables);
		}
		Hash hash;
		size_t hash0 = hash(kv.first) % _tables.size();
		size_t hashi = hash0;
		size_t i = 1;
		while (_tables[hashi]._state == EXIST)
		{
			hashi = (hash0 + i) % _tables.size();
			++i;
		}
		_tables[hashi]._kv = kv;
		_tables[hashi]._state = EXIST;
		++_n;
		return true;
	}
	HashData<K, V>* Find(const K& key)
	{
		Hash hash;
		size_t hash0 = hash(key) % _tables.size();
		size_t hashi = hash0;
		size_t i = 1;
		while (_tables[hashi]._state != EMPTY)
		{
			if (_tables[hashi]._kv.first == key)
			{
				return &_tables[hashi];
			}
			hashi = (hash0 + i) % _tables.size();
			++i;
		}
		return nullptr;
	}
	bool Erase(const K& key)
	{
		HashData<K, V>* ret = Find(key);
		if (ret)
		{
			ret->_state = DELETE;
			--_n;
			return true;
		}
		else
		{
			return false;
		}
	}
private:
	vector<HashData<K, V>> _tables;
	size_t _n = 0;
};
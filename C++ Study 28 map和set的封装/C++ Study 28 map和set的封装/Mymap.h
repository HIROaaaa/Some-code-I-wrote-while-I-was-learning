#pragma once
#include"RBTree.h"
namespace hiro
{
	template<class K, class V>
	class map
	{
		struct MapKeyOfT
		{
			const K& operator()(const pair<K, V>& kv)
			{
				return kv.first;
			}
		};
	public:							//解决map的key不能修改的问题
		typedef typename RBTree<K, pair<const K, V>, MapKeyOfT>::Iterator iterator;
		typedef typename RBTree<K, pair<const K, V>, MapKeyOfT>::ConstIterator const_iterator;
		iterator begin()
		{
			return _t.Begin();
		}
		iterator end()
		{
			return _t.End();
		}
		const_iterator begin()const
		{
			return _t.Begin();
		}
		const_iterator end()const
		{
			return _t.End();
		}
		bool insert(const pair<K, V>& kv)
		{
			return _t.Insert(kv);
		}
	private:     //解决set的key不能修改的问题
		RBTree<K, pair<const K, V>, MapKeyOfT> _t;
	};
}
#pragma once
#include"RBTree.h"
namespace hiro
{
	template<class K>
	class set
	{
		struct SetKeyOfT
		{
			const K& operator()(const K& key)
			{
				return key;
			}
		};
	public:						//解决set的key不能修改的问题
		typedef typename RBTree<K, const K, SetKeyOfT>::Iterator iterator;
		typedef typename RBTree<K, const K, SetKeyOfT>::ConstIterator const_iterator;

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
		bool insert(const K& key)
		{
			return _t.Insert(key);
		}
	private://解决set的key不能修改的问题
		RBTree<K,const K, SetKeyOfT> _t;
	};
}
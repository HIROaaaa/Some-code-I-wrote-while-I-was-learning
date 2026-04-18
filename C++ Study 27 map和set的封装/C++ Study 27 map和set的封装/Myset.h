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
	public:
		bool insert(const K& key)
		{
			return _t.Insert(key);
		}
	private:
		RBTree<K,K, SetKeyOfT> _t;
	};
}
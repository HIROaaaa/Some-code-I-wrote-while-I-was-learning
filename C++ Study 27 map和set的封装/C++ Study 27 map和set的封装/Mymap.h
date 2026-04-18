#pragma once
#include"RBTree.h"
namespace hiro
{
	template<class K,class V>
	class map
	{
		struct MapKeyOfT
		{
			const K& operator()(const pair<K,V> kv)
			{
				return kv.first;
			}
		};
	private:
		RBTree<K, pair<K, V>, MapKeyOfT> _t;
	};
}
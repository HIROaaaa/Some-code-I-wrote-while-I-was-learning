#pragma once
#include <algorithm>
#include<vector>
namespace hiro
{
	template<class T,class Container=vector<T>>
	class priority_queue
	{
	public:
		void Swap(T& a, T& b)
		{
			T tmp = a;
			a = b;
			b = tmp;
		}
		void AdjustUp(int child)
		{
			int parent = (child - 1) / 2;
			while (child > 0)
			{
				//默认大堆
				if (_con[parent] < _con[child])
				{
					Swap(_con[parent], _con[child]);
					child = parent;
					parent = (child - 1) / 2;
				}
				else
				{
					break;
				}
			}
		}
		void AdjustDown(int parent)
		{
			int child = parent * 2 + 1;
			while (child < _con.size())
			{
				if (child + 1 < _con.size() && _con[child] < _con[child + 1])
				{
					child++;
				}
				if (_con[parent] < _con[child])
				{
					Swap(_con[parent], _con[child]);
					parent = child;
					child = parent * 2 + 1;
				}
				else
				{
					break;
				}
			}
		}
		void push(const T& x )
		{
			_con.push_back(x);
			AdjustUp(_con.size()-1);
		}
		void pop()
		{
			std::swap(_con[0], _con[_con.size() - 1]);
			_con.pop_back();
			AdjustDown(0);
		}
		const T& top()const
		{
			return _con[0];
		}
		// 判空
		bool empty() const
		{
			return _con.empty();
		}

		// 元素个数
		size_t size() const
		{
			return _con.size();
		}
	private:
		Container _con;
	};
}

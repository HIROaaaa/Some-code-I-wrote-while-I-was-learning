
using namespace std;
#include "HashTable.h"

int main()
{
	int a[] = { 1,3,14,2,123,32,41,45 };
	HashTable<int, int> ht;
	for (auto e : a)
	{
		ht.Insert({e, e});
	}
	ht.Insert({15,15});
	return 0;
}
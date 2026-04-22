#include<string>
using namespace std;

#include"HashTable.h"
struct StringHashFunc
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
int main()
{
	const char* a[] = { "abcd","sort","insert" };
	HashTable<string, string, StringHashFunc> ht;
	for (auto e : a)
	{
		ht.Insert({e,e});
	}
	return 0;
}
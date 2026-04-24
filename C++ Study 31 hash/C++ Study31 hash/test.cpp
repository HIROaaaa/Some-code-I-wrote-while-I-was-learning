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

	return 0;
}
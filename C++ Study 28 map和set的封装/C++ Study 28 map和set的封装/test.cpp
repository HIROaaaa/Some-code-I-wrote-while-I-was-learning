#include<iostream>
using namespace std;
#include"Myset.h"
#include"Mymap.h"

int main()
{
	hiro::set<int> s;
	s.insert(1);
	s.insert(4);
	s.insert(10);
	s.insert(3);
	s.insert(6);
	hiro::set<int>::iterator sit = s.begin();
	//*sit = 5;
	while (sit != s.end())
	{
		cout << *sit << " ";
		++sit;
	}
	cout << endl;

	hiro::map<int,int> dict;
	dict.insert({ 1,2 });
	dict.insert({ 2,4 });
	dict.insert({ 3,6 });
	dict.insert({ 4,8 });
	dict.insert({ 5,10 });
	hiro::map<int, int>::iterator mit = dict.begin();
	while (mit != dict.end())
	{
		cout << (*mit).first <<":"<<(*mit).second<<" ";
		++mit;
	}
	cout << endl;
	return 0;
}
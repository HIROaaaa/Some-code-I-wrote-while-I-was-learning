#include <iostream>
#include <set>
using namespace std;
int main()
{
    set<int> s;
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(4);
    auto it = s.begin();
    while (it != s.end())
    {
        cout << *it << " ";
        ++it;
    }
    cout << endl;
    s.insert({ 1, 312, 41, 1, 41, 3 });
    it = s.begin();
    while (it != s.end())
    {
        cout << *it << " ";
        ++it;
    }
    cout << endl;
    // set<string> strset = {"hello", "world", "hello"};
    // set<string>::iterator sit = strset.begin();
    // while (sit != strset.end())
    // {
    //     cout << *sit << " ";
    //     ++sit;
    // }
    // cout << endl;
    s.insert({ 10,20,30,40,50,60,55,23,42,99999 });
    auto itlow = s.lower_bound(19);
    auto itup = s.upper_bound(61);
    s.erase(itlow, itup);
    it = s.begin();
    while (it != s.end())
    {
        cout << *it << " ";
        ++it;
    }
    cout << endl;
    return 0;
}
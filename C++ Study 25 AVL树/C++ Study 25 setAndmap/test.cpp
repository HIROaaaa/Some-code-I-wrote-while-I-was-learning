#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

//前K个高频单词
using namespace std;
class Solution {
public:
    struct kvCopmare
    {
        bool operator()(const pair<string, int>& kv1, const pair<string, int>& kv2)
        {
            return kv1.second > kv2.second;
        }
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string, int> countMap;
        for (auto& e : words)
        {
            countMap[e]++;
        }
        vector<pair<string, int>> v(countMap.begin(), countMap.end());
        stable_sort(v.begin(), v.end(), kvCopmare());
        vector<string> vret;
        for (int i = 0;i < k;++i)
        {
            vret.push_back(v[i].first);
        }
        return vret;
    }
};
int main()
{

	return 0;
}
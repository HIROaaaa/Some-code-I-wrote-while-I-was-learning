#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;
class Solution
{
public:
    bool isLetter(char ch)
    {
        if (ch >= 'a' && ch <= 'z')
            return true;
        if (ch >= 'A' && ch <= 'Z')
            return true;
        return false;
    }
    string reverseOnlyLetters(string s)
    {
        int left = 0, right = s.size() - 1;
        while (left < right)
        {
            while (left < right && !isLetter(s[left]))
            {
                ++left;
            }
            while (left < right && !isLetter(s[right]))
            {
                --right;
            }
            swap(s[left++], s[right--]);
        }
        return s;
    }
    int firstUniqChar(string s) {
        int count[26] = { 0 };
        for (auto ch : s)
        {
            count[ch - 'a']++;
        }
        for (int i = 0; i < s.size(); ++i)
        {
            if (count[s[i] - 'a'] == 1)
                return i;
        }
        return -1;
    }
    string addStrings(string num1, string num2) {
        int end1 = num1.size() - 1, end2 = num2.size() - 1;
        int next = 0;
        string tmp;
        while (end1 >= 0 || end2 >= 0)
        {
            int val1 = end1 >= 0 ? num1[end1--] - '0' : 0;
            int val2 = end2 >= 0 ? num2[end2--] - '0' : 0;
            int ret = val1 + val2 + next;
            next = ret / 10;
            ret = ret % 10;
            tmp.insert(tmp.begin(), ret + '0');
        }
        if (next)
        {
            tmp.insert(tmp.begin(), '1');
        }
        return tmp;
    }
};
void test1()
{
    string s1 = "hello world";
    s1.push_back(' ');
    s1.push_back('x');//尾插字符

    s1.append("yyyy");//尾插字符串

    s1 += "bbb";//这样的尾插更好用
    cout << s1 << endl;

    s1.insert(0,"aa");//头插//在第n个位置插入

    s1.insert(0, 1, 'a');//插入一个需要这么写
    //s1.insert(0,'a');          //这样写不行，没有提供这种写法
    cout << s1 << endl;

    s1.erase(5, 1);//在第a个位置开始删除b个字符
    cout << s1 << endl;

    s1.erase(s1.begin());//头删
    cout << s1 << endl;

    s1.erase(s1.end()--);//尾删
    cout << s1 << endl;

    s1.erase(6);  //第n个后面全删
    cout << s1 << endl;

    s1.replace(4, 1, "&");  
    cout << s1 << endl;

    //把s2里的所有空格都换成%
    string s2 = "hello world 11 222 333 ";
    cout << s2 << endl;
    size_t pos = s2.find(' ');//在s2中找到空格的位置并返回其索引
    while (pos != string::npos)
    {
        s2.replace(pos, 1, "%%");
        pos = s2.find(' ',pos + 2);//后面可以加上寻找开始的位置
    }
    cout << s2 << endl;

    auto str1 = s2.c_str(); //输出s2字符串的指针，这是用来兼容c的
    //比如
    //string file;
    //cin >> file;
    //FILE* fout = fopen(file.c_str(), "r");
    //char ch=fgetc(fout);
    //while (ch != EOF)
    //{
    //    cout << ch;
    //    ch = fgetc(fout);
    //}
    //fclose(fout);

    string str3 = "hello world abc";
    size_t pos2 = str3.find(" ");   
    //size_t pos2 = str3.rfind(" ");  如果是找abc就可以这样

    string suffix ="1111111111111111";
    suffix = str3.substr(pos2);  //用s3从pos位置往后的内容覆盖suffix
    cout << suffix << endl;
}
int main()
{
	string s1 = "hello world";
	s1.resize(20,'x');  //会扩容，也会缩小  
	s1.resize(20);  //没有指定的时候会把开的空间设置成  '\0'


 /*   Solution sol;
    string test1 = "a-bC-dEf-ghIj";
    string res1 = sol.reverseOnlyLetters(test1);
    cout << "测试用例1：" << test1 << endl;
    cout << "预期结果：j-Ih-gfE-dCba-" << endl;
    cout << "实际结果：" << res1 << endl << endl;*/

    test1();


	return 0;
}
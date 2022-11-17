/*
    LeetCode:884


        思路：
            1.用栈存储，每次遇到#pop一个元素。

*/

#include <iostream>
#include <cmath>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    bool backspaceCompare(string s, string t)
    {
        s = toNewsting(s);
        t = toNewsting(t);
        return s == t;
    }
    string toNewsting(string s)
    {
        string ans;
        for (int Index = 0; Index < s.length(); Index++)
        {
            if (s[Index] != '#')
            {
                ans.push_back(s[Index]);
            }
            else if (!ans.empty())
            {
                ans.pop_back();
            }
        }
        return ans;
    }
};

int main()
{
    string s = "a#cdd";
    string t = "b";
    Solution solution;
    bool box = solution.backspaceCompare(s, t);
    cout << box << endl;
    return 0;
}

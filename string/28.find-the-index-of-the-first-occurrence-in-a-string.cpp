// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=28 lang=cpp
 * @lcpr version=30111
 *
 * [28] 找出字符串中第一个匹配项的下标
 */

// @lcpr-template-start
using namespace std;
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
// @lcpr-template-end
// @lc code=start
class Solution
{
public:
    // strStr()函数 暴力解法也可以过
    int strStr(string haystack, string needle)
    {
        int source = haystack.size();
        int sub = needle.size();
        for (int i = 0; i <= source - sub; i++)
        {
            int j;
            for (j = 0; j < sub; j++)
            {
                if (needle[j] != haystack[i + j])
                    break;
            }
            if (j == sub)
                return i;
        }
        return -1;
    }
};
// @lc code=end

/*
// @lcpr case=start
// "sadbutsad"\n"sad"\n
// @lcpr case=end

// @lcpr case=start
// "leetcode"\n"leeto"\n
// @lcpr case=end

 */

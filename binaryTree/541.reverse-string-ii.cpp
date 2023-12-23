// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=541 lang=cpp
 * @lcpr version=30111
 *
 * [541] 反转字符串 II
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
    void rstring(string &s, int start, int end)
    {
        while (start < end)
        {
            char temp = s[start];
            s[start] = s[end];
            s[end] = temp;
            start++;
            end--;
        }
    }
    string reverseStr(string s, int k)
    {
        int start = 0, end = s.size(), count = 0, i = 0;

        // 第一句 实现反转前k个
        for (i = 0; i < end; i++)
        {
            count++;
            if (count == 2 * k)
            {
                rstring(s, i - count + 1, i - k);
                count = 0;
            }
        }
        // 处理结尾
        if (count < k)
            rstring(s, end - count, end - 1);
        if (count >= k)
            rstring(s, end - count, end - 1 - count % k);

        return s;
    }
};
// @lc code=end

/*
// @lcpr case=start
// "abcdefg"\n2\n
// @lcpr case=end

// @lcpr case=start
// "abcd"\n2\n
// @lcpr case=end

 */

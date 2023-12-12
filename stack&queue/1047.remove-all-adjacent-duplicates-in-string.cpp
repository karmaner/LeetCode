// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=1047 lang=cpp
 * @lcpr version=30111
 *
 * [1047] 删除字符串中的所有相邻重复项
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
    string removeDuplicates(string s)
    {
        stack<char> st;
        string ans = "";
        st.push(s[0]);
        for (int i = 1; i < s.size(); i++)
        {
            if (st.empty() || st.top() != s[i])
                st.push(s[i]);
            else
                st.pop();
        }

        while (!st.empty())
        {
            ans += st.top();
            st.pop();
        }
        for (int i = 0, j = ans.size() - 1; i <= j; i++, j--)
        {
            swap(ans[i], ans[j]);
        }
        return ans;
    }
};

// @lc code=end

/*
// @lcpr case=start
// "abbaca"\n
// @lcpr case=end

 */

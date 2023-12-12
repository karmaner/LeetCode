/*
 * @lc app=leetcode.cn id=20 lang=cpp
 * @lcpr version=30111
 *
 * [20] 有效的括号
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
    bool isValid(string s)
    {
        stack<char> st;
        for (int i = 0; i < s.size(); i++)
        {
            switch (s[i])
            {
            case '(':
                st.push(s[i]);
                break;
            case '[':
                st.push(s[i]);
                break;
            case '{':
                st.push(s[i]);
                break;
            case ')':
                if (st.empty())
                    return false;
                if (st.top() == '(')
                    st.pop();
                else
                    st.push(s[i]);
                break;
            case '}':
                if (st.empty())
                    return false;
                if (st.top() == '{')
                    st.pop();
                else
                    st.push(s[i]);
                break;
            case ']':
                if (st.empty())
                    return false;
                if (st.top() == '[')
                    st.pop();
                else
                    st.push(s[i]);
                break;
            default:
                st.push(s[i]);
                break;
            }
        }
        return st.empty();
    }
};
// @lc code=end

/*
// @lcpr case=start
// "()"\n
// @lcpr case=end

// @lcpr case=start
// "()[]{}"\n
// @lcpr case=end

// @lcpr case=start
// "(]"\n
// @lcpr case=end

 */

/*
 * @lc app=leetcode.cn id=202 lang=cpp
 * @lcpr version=30111
 *
 * [202] 快乐数
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
    bool isHappy(int n)
    {
        if (n > 1 && n < 10 && n != 7)
            return false;
        string s = to_string(n);

        int new_n = 0;
        for (auto ch : s)
        {
            int a = ch - '0';
            new_n += a * a;
        }
        if (new_n == 1)
            return true;
        else
            return isHappy(new_n);
    }
};
// @lc code=end

/*
// @lcpr case=start
// 19\n
// @lcpr case=end

// @lcpr case=start
// 2\n
// @lcpr case=end

 */

/*
 * @lc app=leetcode.cn id=387 lang=cpp
 * @lcpr version=30111
 *
 * [387] 字符串中的第一个唯一字符
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
    int firstUniqChar(string s)
    {

        unordered_map<char, int> char_count;
        // init
        for (auto ch : s)
        {
            char_count[ch]++;
        }
        for (int i = 0; i < s.size(); i++)
        {
            if (char_count[s[i]] == 1)
                return i;
        }
        return -1;
    }
};
// @lc code=end

/*
// @lcpr case=start
// "leetcode"\n
// @lcpr case=end

// @lcpr case=start
// "loveleetcode"\n
// @lcpr case=end

// @lcpr case=start
// "aabb"\n
// @lcpr case=end

 */

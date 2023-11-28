/*
 * @lc app=leetcode.cn id=242 lang=cpp
 * @lcpr version=30111
 *
 * [242] 有效的字母异位词
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
    bool isAnagram(string s, string t)
    {
        unordered_map<char, int> s_num;
        unordered_map<char, int> t_num;

        for (auto ch : s)
        {
            s_num[ch]++;
        }

        for (auto ch : t)
        {
            t_num[ch]++;
        }

        if (s_num.size() != t_num.size())
            return false;
        for (auto iter : s_num)
        {
            if (t_num[iter.first] != iter.second)
                return false;
        }
        return true;
    }
};
// @lc code=end

/*
// @lcpr case=start
// "anagram"\n"nagaram"\n
// @lcpr case=end

// @lcpr case=start
// "rat"\n"car"\n
// @lcpr case=end

 */

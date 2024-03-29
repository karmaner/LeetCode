/*
 * @lc app=leetcode.cn id=349 lang=cpp
 * @lcpr version=30111
 *
 * [349] 两个数组的交集
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
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_map<int, int> map1;
        unordered_map<int, int> map2;
        for (auto i : nums1)
        {
            map1[i] = 1;
        }
        for (auto i : nums2)
        {
            map2[i] = 1;
        }
        vector<int> ans;
        for (auto i : map1)
        {
            if (map2[i.first] == 1)
                ans.push_back(i.first);
        }
        return ans;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,2,1]\n[2,2]\n
// @lcpr case=end

// @lcpr case=start
// [4,9,5]\n[9,4,9,8,4]\n
// @lcpr case=end

 */

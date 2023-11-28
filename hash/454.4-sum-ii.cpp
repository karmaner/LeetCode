/*
 * @lc app=leetcode.cn id=454 lang=cpp
 * @lcpr version=30111
 *
 * [454] 四数相加 II
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
    int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3, vector<int> &nums4)
    {
        unordered_map<int, int> umap;
        // 记录ab两数之和
        for (int a : nums1)
        {
            for (int b : nums2)
            {
                umap[a + b]++;
            }
        }
        int count = 0;
        for (int c : nums3)
        {
            for (int d : nums4)
            {
                if (umap[0 - c - d] != 0)
                    count += umap[0 - c - d];
            }
        }
        return count;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,2]\n[-2,-1]\n[-1,2]\n[0,2]\n
// @lcpr case=end

// @lcpr case=start
// [0]\n[0]\n[0]\n[0]\n
// @lcpr case=end

 */

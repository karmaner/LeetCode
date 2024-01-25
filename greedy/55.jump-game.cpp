/*
 * @lc app=leetcode.cn id=55 lang=cpp
 * @lcpr version=30113
 *
 * [55] 跳跃游戏
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
class Solution {
 public:
  bool canJump(vector<int>& nums) {
    if (nums.size() < 2) return true;
    int cover = 0;
    for (int i = 0; i < nums.size(); i++) {
      if (i > cover) return false;

      cover = max(cover, i + nums[i]);
    }
    return true;
  }
};
// @lc code=end

/*
// @lcpr case=start
// [2,3,1,1,4]\n
// @lcpr case=end

// @lcpr case=start
// [3,2,1,0,4]\n
// @lcpr case=end

 */

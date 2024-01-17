/*
 * @lc app=leetcode.cn id=47 lang=cpp
 * @lcpr version=30113
 *
 * [47] 全排列 II
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
  vector<vector<int>> ans;
  vector<int> path;
  void backtracking(vector<int>& nums, vector<bool>& used)
  {
    if (path.size() == nums.size()) {
      ans.push_back(path);
      return;
    }

    for (int i = 0; i < nums.size(); i++) {
      if (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false)
        continue;
      if (used[i] == false) {
        path.push_back(nums[i]);
        used[i] = true;
        backtracking(nums, used);
        path.pop_back();
        used[i] = false;
      }
    }
  }
  vector<vector<int>> permuteUnique(vector<int>& nums)
  {
    vector<bool> used(nums.size(), false);
    sort(nums.begin(), nums.end());
    backtracking(nums, used);
    return ans;
  }
};
// @lc code=end

/*
// @lcpr case=start
// [1,1,2]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3]\n
// @lcpr case=end

 */

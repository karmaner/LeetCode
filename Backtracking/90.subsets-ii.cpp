// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=90 lang=cpp
 * @lcpr version=30113
 *
 * [90] 子集 II
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
  // 记录结果
  vector<vector<int>> ans;

  // 记录路径
  vector<int> path;

  // 回溯算法 相比78 需要对元素去重
  void backtracking(vector<int>& nums, int startIndex, vector<bool>& used)
  {

    ans.push_back(path);

    for (int i = startIndex; i < nums.size(); i++) {
      // used[i - 1] == true，说明同一树枝candidates[i - 1]使用过
      // used[i - 1] == false，说明同一树层candidates[i - 1]使用过
      // 而我们要对同一树层使用过的元素进行跳过
      if (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false)
        continue;
      path.push_back(nums[i]);
      used[i] = true;
      backtracking(nums, i + 1, used);
      path.pop_back();
      used[i] = false;
    }
  }
  vector<vector<int>> subsetsWithDup(vector<int>& nums)
  {
    sort(nums.begin(), nums.end());
    vector<bool> used(nums.size(), false);
    backtracking(nums, 0, used);
    return ans;
  }
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,2]\n
// @lcpr case=end

// @lcpr case=start
// [0]\n
// @lcpr case=end

 */

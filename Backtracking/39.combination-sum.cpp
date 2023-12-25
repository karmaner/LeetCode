/*
 * @lc app=leetcode.cn id=39 lang=cpp
 * @lcpr version=30112
 *
 * [39] 组合总和
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

  // 写成排列问题了 需要添加控制参数
  void backtracing(vector<int>& candidates, int target, int sum, int startIndex)
  {
    if (sum == target) {
      ans.push_back(path);
      return;
    }
    if (sum > target)
      return;

    for (int i = startIndex; i < candidates.size(); i++) {
      sum += candidates[i];
      path.push_back(candidates[i]);
      backtracing(candidates, target, sum, i); // 递归
      sum -= candidates[i];                    // 回溯
      path.pop_back();                         // 回溯
    }
    return;
  }
  vector<vector<int>> combinationSum(vector<int>& candidates, int target)
  {
    backtracing(candidates, target, 0, 0);
    return ans;
  }
};
// @lc code=end

/*
// @lcpr case=start
// [2,3,6,7]\n7\n
// @lcpr case=end

// @lcpr case=start
// [2,3,5]\n8\n
// @lcpr case=end

// @lcpr case=start
// [2]\n1\n
// @lcpr case=end

 */

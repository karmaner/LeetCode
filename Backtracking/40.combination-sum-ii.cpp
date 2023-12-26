/*
 * @lc app=leetcode.cn id=40 lang=cpp
 * @lcpr version=30112
 *
 * [40] 组合总和 II
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
  // 剪纸总是那么难以理解
  vector<int> path;
  vector<vector<int>> ans;
  void backtracing(vector<int>& candidates,
                   int target,
                   int sum,
                   int startIndex,
                   vector<bool>& used)
  {
    if (sum > target)
      return;
    if (sum == target) {
      ans.push_back(path);
      return;
    }

    for (int i = startIndex; i < candidates.size(); i++) {
      if (i > 0 && candidates[i] == candidates[i - 1] && used[i - 1] == false) {
        continue;
      }
      sum += candidates[i];
      path.push_back(candidates[i]);
      used[i] = true;
      backtracing(candidates, target, sum, i + 1, used);
      used[i] = false;
      sum -= candidates[i];
      path.pop_back();
    }
  }
  vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
  {
    vector<bool> used(candidates.size(), false);

    // 把相同数据 相邻
    sort(candidates.begin(), candidates.end());
    backtracing(candidates, target, 0, 0, used);
    return ans;
  }
};
// @lc code=end

/*
// @lcpr case=start
// [10,1,2,7,6,1,5]\n8\n
// @lcpr case=end

// @lcpr case=start
// [2,5,2,1,2]\n5\n
// @lcpr case=end

 */

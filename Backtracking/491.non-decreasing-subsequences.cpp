/*
 * @lc app=leetcode.cn id=491 lang=cpp
 * @lcpr version=30113
 *
 * [491] 非递减子序列
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
  // 结果
  vector<vector<int>> ans;

  // 路径
  vector<int> path;

  /** 回溯算法 */
  void backtracking(vector<int>& nums, int startIndex)
  {
    // 结果过滤
    if (path.size() >= 2) {
      ans.push_back(path);
    }
    unordered_set<int> uset; // 使用set来对本层元素进行去重
    for (int i = startIndex; i < nums.size(); i++) {

      for (int i = startIndex; i < nums.size(); i++) {
        if ((!path.empty() && nums[i] < path.back()) ||
            uset.find(nums[i]) != uset.end()) {
          continue;
        }
        uset.insert(nums[i]); // 记录这个元素在本层用过了，本层后面不能再用了
        path.push_back(nums[i]);
        backtracking(nums, i + 1);
        path.pop_back();
      }
    }
  }
  vector<vector<int>> findSubsequences(vector<int>& nums)
  {
    backtracking(nums, 0);
    return ans;
  }
};
// @lc code=end

/*
// @lcpr case=start
// [4,6,7,7]\n
// @lcpr case=end

// @lcpr case=start
// [4,4,3,2,1]\n
// @lcpr case=end

 */

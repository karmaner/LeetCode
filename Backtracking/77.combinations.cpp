// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=77 lang=cpp
 * @lcpr version=30112
 *
 * [77] 组合
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
private:
  vector<int> path; // 记录路径
  vector<vector<int>> ans;

  void backtracking(int n, int k, int startIndex)
  {
    if (path.size() == k) {
      ans.push_back(path);
      return;
    }
    // for (int i = startIndex; i <= n; i++) {
    for (int i = startIndex; i <= n - (k - path.size()) + 1; i++) { // 剪枝优化
      path.push_back(i); // 加入结果集
      backtracking(n, k, i + 1);
      path.pop_back(); // 回溯
    }
  }

public:
  vector<vector<int>> combine(int n, int k)
  {
    backtracking(n, k, 1);
    return ans;
  }
};
// @lc code=end

/*
// @lcpr case=start
// 4\n2\n
// @lcpr case=end

// @lcpr case=start
// 1\n1\n
// @lcpr case=end

 */

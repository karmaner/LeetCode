/*
 * @lc app=leetcode.cn id=216 lang=cpp
 * @lcpr version=30112
 *
 * [216] 组合总和 III
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
  vector<int> path;        // 结果集
  vector<vector<int>> ans; // 最终返回结果

  void backtracing(int k, int n, int startIndex)
  {
    if (path.size() == k) {
      int sum = 0;
      for (auto i : path)
        sum += i;
      if (sum == n)
        ans.push_back(path);
      return;
    }
    for (int i = startIndex; i <= 9; i++) {
      path.push_back(i);
      backtracing(k, n, i + 1);
      path.pop_back();
    }
  }

public:
  vector<vector<int>> combinationSum3(int k, int n)
  {
    backtracing(k, n, 1);
    return ans;
  }
};
// @lc code=end

/*
// @lcpr case=start
// 3\n7\n
// @lcpr case=end

// @lcpr case=start
// 3\n9\n
// @lcpr case=end

// @lcpr case=start
// 4\n1\n
// @lcpr case=end

 */

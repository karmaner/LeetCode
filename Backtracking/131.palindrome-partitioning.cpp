/*
 * @lc app=leetcode.cn id=131 lang=cpp
 * @lcpr version=30112
 *
 * [131] 分割回文串
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
  vector<string> path;
  vector<vector<string>> ans;

  // 判断回文字符串     给两个参数就不用切割原字符串了
  bool isPalindrome(string target, int left, int right)
  {

    for (int i = left, j = right; i < j; i++, j--) {
      if (target[i] != target[j])
        return false;
    }
    return true;
  }
  void backtracing(string s, int startIndex)
  {
    // 结束条件
    if (startIndex >= s.size()) {
      ans.push_back(path);
      return;
    }

    for (int i = startIndex; i < s.size(); i++) {
      if (isPalindrome(s, startIndex, i)) {
        string str = s.substr(startIndex, i - startIndex + 1);
        path.push_back(str);
      } else {
        continue;
      }
      backtracing(s, i + 1);
      path.pop_back();
    }
  }
  vector<vector<string>> partition(string s)
  {
    backtracing(s, 0);
    return ans;
  }
};
// @lc code=end

/*
// @lcpr case=start
// "aab"\n
// @lcpr case=end

// @lcpr case=start
// "a"\n
// @lcpr case=end

 */

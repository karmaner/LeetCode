/*
 * @lc app=leetcode.cn id=14 lang=cpp
 * @lcpr version=30118
 *
 * [14] 最长公共前缀
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
  string longestCommonPrefix(vector<string>& strs) {
    if (strs.empty()) return "";

    for (int i = 0; i < strs[0].size(); i++) {
      char pre = strs[0][i];
      for (int j = 1; j < strs.size(); j++) {
        if (i > strs[j].size() || strs[j][i] != pre) {
          return strs[0].substr(0, i);
        }
      }
    }
    return strs[0];
  }
};
// @lc code=end

/*
// @lcpr case=start
// ["flower","flow","flight"]\n
// @lcpr case=end

// @lcpr case=start
// ["dog","racecar","car"]\n
// @lcpr case=end

 */

/*
 * @lc app=leetcode.cn id=17 lang=cpp
 * @lcpr version=30112
 *
 * [17] 电话号码的字母组合
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
  const string letterMap[10] = {
    "",     // 0
    "",     // 1
    "abc",  // 2
    "def",  // 3
    "ghi",  // 4
    "jkl",  // 5
    "mno",  // 6
    "pqrs", // 7
    "tuv",  // 8
    "wxyz", // 9
  };

public:
  vector<string> ans;
  string s;

  void backtracking(const string& digits, int index)
  {
    if (index == digits.size()) {
      ans.push_back(s);
      return;
    }
    int digit = digits[index] - '0';   // 将index指向的数字转为int
    string letters = letterMap[digit]; // 取数字对应的字符集
    for (int i = 0; i < letters.size(); i++) {
      s.push_back(letters[i]);
      backtracking(digits, index + 1);
      s.pop_back();
    }
  }

  vector<string> letterCombinations(string digits)
  {
    if (digits.size() == 0) {
      return ans;
    }
    backtracking(digits, 0);
    return ans;
  }
};
// @lc code=end

/*
// @lcpr case=start
// "23"\n
// @lcpr case=end

// @lcpr case=start
// ""\n
// @lcpr case=end

// @lcpr case=start
// "2"\n
// @lcpr case=end

 */

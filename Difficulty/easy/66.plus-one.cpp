// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=66 lang=cpp
 * @lcpr version=30119
 *
 * [66] 加一
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
  vector<int> plusOne(vector<int>& digits) {
    int len = digits.size();
    int i = 1;
    while (len >= i && (digits[len - i] + 1) == 10) {
      digits[len - i] = 0;
      i++;
    }
    if (i > len) {
      digits.insert(digits.begin(), 1);
      return digits;
    }
    digits[len - i] += 1;
    return digits;
  }
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [4,3,2,1]\n
// @lcpr case=end

// @lcpr case=start
// [0]\n
// @lcpr case=end

 */

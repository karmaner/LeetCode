// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=58 lang=cpp
 * @lcpr version=30122
 *
 * [58] 最后一个单词的长度
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
  int lengthOfLastWord(string s) {
    int end = 0;
    int start = s.size() - 1;
    // 寻找最后一个单词 并且保持位置
    while (start >= 0 && s[start] == ' ') {
      start--;
    }
    // 单词长度
    end = start;
    while (end >= 0 && s[end] != ' ') {  // 短路操作
      end--;
    }
    return start - end;
}
};
// @lc code=end

/*
// @lcpr case=start
// "Hello World"\n
// @lcpr case=end

// @lcpr case=start
// "   fly me   to   the moon  "\n
// @lcpr case=end

// @lcpr case=start
// "luffy is still joyboy"\n
// @lcpr case=end

 */

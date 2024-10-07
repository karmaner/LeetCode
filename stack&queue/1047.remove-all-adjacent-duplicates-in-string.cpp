/*
 * @lc app=leetcode.cn id=1047 lang=cpp
 * @lcpr version=30204
 *
 * [1047] 删除字符串中的所有相邻重复项
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
    string removeDuplicates(string s) {
        string stk;
        for(auto c : s) {
            if(stk.empty()) {
                stk.push_back(c);
            } else {
                if(c == stk.back()) {
                    stk.erase(stk.end() - 1);
                } else {
                    stk.push_back(c);
                }
            }
        }
        return stk;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "abbaca"\n
// @lcpr case=end

 */


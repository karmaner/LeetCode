/*
 * @lc app=leetcode.cn id=367 lang=cpp
 * @lcpr version=30204
 *
 * [367] 有效的完全平方数
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
    bool s(int num) {
        if(num == 0 || num == 1) return true; // 0 和 1 是特殊情况
        int left = 1, right = num; // 从 1 开始，避免 num == 0 的问题
        while(left <= right) {
            int mid = left + (right - left) / 2; // 防止溢出
            if(mid == num / mid && num % mid == 0) { // 使用除法避免溢出
                return true;
            } else if(mid > num / mid) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return false;
    }
public:
    bool isPerfectSquare(int num) {
        return s(num);
    }
};
// @lc code=end



/*
// @lcpr case=start
// 16\n
// @lcpr case=end

// @lcpr case=start
// 14\n
// @lcpr case=end

 */


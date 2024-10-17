// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=509 lang=cpp
 * @lcpr version=30114
 *
 * [509] 斐波那契数
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
    int s1_fib(int n) {
        if(n == 0) return 0;
        if(n == 1) return 1;
        return  s1_fib(n - 1) + s1_fib(n - 2);
    }

    int s2_fib(int n) {
        vector<int> dp(n + 1, 0);
        dp[0] = 0;
        dp[1] = 1;
        for(int i = 2; i < n + 1; ++i) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }

    int s3_fib(int n) {
        if(n == 0 || n == 1) return n;
        int pre = 0;
        int cur = 1;
        int next = 0;
        for(int i = 1; i < n; ++i) {
            next = pre + cur;
            pre = cur;
            cur = next;
        }
        return cur;
    }
    int fib(int n) {
        return s3_fib(n);
    }
};
// @lc code=end

/*
// @lcpr case=start
// 2\n
// @lcpr case=end

// @lcpr case=start
// 3\n
// @lcpr case=end

// @lcpr case=start
// 4\n
// @lcpr case=end

 */

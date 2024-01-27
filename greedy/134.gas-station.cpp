// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=134 lang=cpp
 * @lcpr version=30113
 *
 * [134] 加油站
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
  // 暴力超时
  int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    // for (int i = 0; i < cost.size(); i++) {
    //   int rest = gas[i] - cost[i];  // 记录剩余油量
    //   int index = (i + 1) % cost.size();
    //   while (
    //       rest > 0 &&
    //       index !=
    //           i) {  //
    //           模拟以i为起点行驶一圈（如果有rest==0，那么答案就不唯一了）
    //     rest += gas[index] - cost[index];
    //     index = (index + 1) % cost.size();
    //   }
    //   // 如果以i为起点跑一圈，剩余油量>=0，返回该起始位置
    //   if (rest >= 0 && index == i) return i;
    // }
    // return -1;

    // // 分类讨论
    // int sum = 0;
    // int min = INT_MAX;  // 从起点开始，油箱的油量最小值

    // // 找最小值  求和
    // for (int i = 0; i < gas.size(); i++) {
    //   int rest = gas[i] - cost[i];
    //   sum += rest;
    //   if (sum < min) {
    //     min = sum;
    //   }
    // }

    // if (sum < 0) return -1;  // 走不通
    // if (min >= 0) return 0;  // 每个地点都可以跑到

    // for (int i = gas.size() - 1; i >= 0; i--) {
    //   int rest = gas[i] - cost[i];
    //   min += rest;
    //   if (min >= 0) return i;
    // }
    // return -1;

    // 贪心算法
    int curSum = 0;
    int totalSum = 0;
    int start = 0;
    for (int i = 0; i < gas.size(); i++) {
      int rest = gas[i] - cost[i];
      curSum += rest;
      totalSum += rest;

      if (curSum < 0) {
        start = i + 1;
        curSum = 0;
      }
    }
    if (totalSum < 0) return -1;

    return start;
  }
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,3,4,5]\n[3,4,5,1,2]\n
// @lcpr case=end

// @lcpr case=start
// [2,3,4]\n[3,4,3]\n
// @lcpr case=end

 */

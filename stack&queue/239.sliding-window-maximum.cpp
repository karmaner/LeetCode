/*
 * @lc app=leetcode.cn id=239 lang=cpp
 * @lcpr version=30111
 *
 * [239] 滑动窗口最大值
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
  // 单调队列  不用全部维护  维护2个元素  一个最大 一个第二大
  class MyQueue
  {
  public:
    deque<int> que;
    void pop(int value)
    {
      if (!que.empty() && value == que.front()) {
        que.pop_front();
      }
    }
    void push(int value)
    {
      // 找到大元素的插入位置
      while (!que.empty() && value > que.back()) {
        que.pop_back();
      }
      que.push_back(value);
    }
    int front() { return que.front(); }
  };

public:
  // 使用辅助队列

  vector<int> maxSlidingWindow(vector<int>& nums, int k)
  {
    MyQueue que;
    vector<int> result;
    for (int i = 0; i < k; i++) { // 先将前k的元素放进队列
      que.push(nums[i]);
    }
    result.push_back(que.front()); // result 记录前k的元素的最大值
    for (int i = k; i < nums.size(); i++) {
      que.pop(nums[i - k]);          // 滑动窗口移除最前面元素
      que.push(nums[i]);             // 滑动窗口前加入最后面的元素
      result.push_back(que.front()); // 记录对应的最大值
    }
    return result;
  }
};
// @lc code=end

/*
// @lcpr case=start
// [1,3,-1,-3,5,3,6,7]\n3\n
// @lcpr case=end

// @lcpr case=start
// [1]\n1\n
// @lcpr case=end

 */

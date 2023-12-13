/*
 * @lc app=leetcode.cn id=347 lang=cpp
 * @lcpr version=30111
 *
 * [347] 前 K 个高频元素
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
  vector<int> topKFrequent(vector<int>& nums, int k)
  {
    vector<int> ans;
    // 频率统计
    unordered_map<int, int> map;
    for (auto i : nums) {
      map[i]++;
    }
    unordered_map<int, int>::iterator it;
    for (int i = 0; i < k; i++) {
      int max = 0, mark = 0;
      for (it = map.begin(); it != map.end(); it++) {
        if (it->second > max) {
          max = it->second;
          mark = it->first;
        }
      }
      ans.push_back(mark);
      map[mark] = -1;
    }
    return ans;
  }
};
// @lc code=end

/*
// @lcpr case=start
// [1,1,1,2,2,3]\n2\n
// @lcpr case=end

// @lcpr case=start
// [1]\n1\n
// @lcpr case=end

 */

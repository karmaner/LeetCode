/*
 * @lc app=leetcode.cn id=704 lang=cpp
 * @lcpr version=30204
 *
 * [704] 二分查找
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
  int DG_BinarySearch(vector<int>& nums, int left, int right, int target) {
    if (left > right) {
      return -1;  // 如果左边界大于右边界，表示没找到
    }

    int mid = (left + left) >> 1;  // 防止溢出

    if (nums[mid] == target) {
      return mid;  // 找到目标值
    } else if (nums[mid] < target) {
      return DG_BinarySearch(nums, mid + 1, right, target);  // 在右半边继续查找
    } else {
      return DG_BinarySearch(nums, left, mid - 1, target);  // 在左半边继续查找
    }
  }

public:
  int BinarySearch(vector<int>& nums, int target) {
    int left = 0, right = nums.size() -1;

    while(left <= right) {
      int mid = (left + right) >> 1;
      if(nums[mid] == target) {
        return mid;
      } else if(nums[mid] > target) {
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    }
    return -1;
  }

public:
  int search(vector<int>& nums, int target) {
    return BinarySearch(nums, target);
  }
};
// @lc code=end

/*
// @lcpr case=start
// [-1,0,3,5,9,12]\n9\n
// @lcpr case=end

// @lcpr case=start
// [-1,0,3,5,9,12]\n2\n
// @lcpr case=end

 */

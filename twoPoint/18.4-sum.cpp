/*
 * @lc app=leetcode.cn id=18 lang=cpp
 * @lcpr version=30204
 *
 * [18] 四数之和
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
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int> > ans;

        sort(nums.begin(), nums.end());

        for(int k = 0; k < nums.size(); ++k) {  // 开始就比他大
            if(nums[k] > 0 && nums[k] > target) {
                return ans;
            }

            if(k > 0 && nums[k] == nums[k - 1]) {  // 相同值
                continue;
            }

            for(int i = k + 1; i < nums.size(); i++) {
                if(nums[k] + nums[i] >= 0 && nums[k] + nums[i] > target) {
                    break;
                }

                if(i > k + 1 && nums[i] == nums[i - 1]) {
                    continue;
                }

                int left = i + 1;
                int right = nums.size() - 1;
                while(left < right) {
                    if((long)nums[k] + nums[i] + nums[left] + nums[right] > target) right--;
                    else if((long)nums[k] + nums[i] + nums[left] + nums[right] < target) left++;
                    else {
                        ans.push_back({nums[k], nums[i], nums[left], nums[right]});
                        // 对nums[left]和nums[right]去重
                        while (right > left && nums[right] == nums[right - 1]) right--;
                        while (right > left && nums[left] == nums[left + 1]) left++;

                        // 找到答案时，双指针同时收缩
                        right--;
                        left++;
                    }
                }
            }
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,0,-1,0,-2,2]\n0\n
// @lcpr case=end

// @lcpr case=start
// [2,2,2,2,2]\n8\n
// @lcpr case=end

 */


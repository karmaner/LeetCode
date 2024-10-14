/*
 * @lc app=leetcode.cn id=376 lang=cpp
 * @lcpr version=30113
 *
 * [376] 摆动序列
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
    int s1_wiggleMaxLength(vector<int>& nums) { 
        if(nums.size() < 2) return nums.size();
        vector<int> op(nums.size() - 1);
        for(int i = 0; i < nums.size() - 1; ++i) {
            op[i] = nums[i + 1] - nums[i];
            cout << op[i] << " ";
        }

        int count = 0;
        for(int i = 0; i < op.size(); ++i) {
            if(i > 0 && op[i]*op[i - 1] < 0) {  // 连续序列
                count++;
            } // 连续序列
            // } else {
            //     count = 1;
            // }
        }
        return count + 1;
    }
    int s2_wiggleMaxLength(vector<int>& nums) {
        if(nums.size() == 1) return 1;
        int ans = 0, last = -2, now;

        for(int i = 1; i < nums.size(); ++i) {
            if(nums[i] == nums[i - 1]) continue;

            now = (nums[i] - nums[i - 1] > 0 ? 1 : -1);
            if(now != last) ans++;
            last = now;
        }
        return ++ans;
    }
public:
    int wiggleMaxLength(vector<int>& nums) {
        return s2_wiggleMaxLength(nums);
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,7,4,9,2,5]\n
// @lcpr case=end

// @lcpr case=start
// [1,17,5,10,13,15,10,5,16,8]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4,5,6,7,8,9]\n
// @lcpr case=end

 */


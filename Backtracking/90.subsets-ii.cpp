// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=491 lang=cpp
 * @lcpr version=30204
 *
 * [491] 非递减子序列
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
#include <set>
#include <utility>
#include <vector>
// @lcpr-template-end
// @lc code=start
class Solution {
vector<int> path;
vector<vector<int> > ans;

void backtracking(int start, vector<int>& nums) {
    if(path.size() > 1)
        ans.push_back(path);

    unordered_set<int> used;  // 用于当前层去重
    for(int i = start; i < nums.size(); ++i) {
        // 如果在同一层递归中已经使用过相同的元素，跳过
        if(used.find(nums[i]) != used.end()) {
            continue;
        }
        
        // 如果当前元素比路径中最后一个元素大或等于，添加到路径中
        if(path.empty() || nums[i] >= path.back()) {    // 短路操作
            used.insert(nums[i]);  // 记录当前元素，避免同一层重复
            path.push_back(nums[i]);
            backtracking(i + 1, nums);
            path.pop_back();  // 回溯，撤销选择
        }
    }
}

public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        ans.clear();
        path.clear();
        backtracking(0, nums);
        return ans;
    }
};

// @lc code=end



/*
// @lcpr case=start
// [4,6,7,7]\n
// @lcpr case=end

// @lcpr case=start
// [4,4,3,2,1]\n
// @lcpr case=end

 */


/*
 * @lc app=leetcode.cn id=78 lang=cpp
 * @lcpr version=30204
 *
 * [78] 子集
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
vector<int> path;
vector<vector<int> > ans;
void backtracking(int start, vector<int>& nums) {

    ans.push_back(path);
    for(int i = start; i < nums.size(); ++i) {
        path.push_back(nums[i]);
        backtracking(i + 1, nums);
        path.pop_back();
    }
}
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        backtracking(0, nums);
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [0]\n
// @lcpr case=end

 */


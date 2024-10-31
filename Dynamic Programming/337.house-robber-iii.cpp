/*
 * @lc app=leetcode.cn id=337 lang=cpp
 * @lcpr version=30204
 *
 * [337] 打家劫舍 III
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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    /**
     * 层次遍历
     * dp[i] = max(dp[i - 1], dp[i - 2] + hierarchical(i))  i表示层次
     */
    int s1_rob(TreeNode* root) {    // 错误解法  层次遍历
        if(!root) return 0;

        queue<TreeNode*> que;
        vector<int> level_sum;
        que.push(root);

        while(!que.empty()) {
            int size = que.size();
            int sum = 0;
            for(int i = 0; i < size; ++i) {
                TreeNode* node = que.front();
                que.pop();
                sum += node->val;
                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);

            }
            level_sum.push_back(sum);
            // cout << que.size() << " " << sum << endl;
        }
        // for(auto i : level_sum) cout << i << " ";
        // vector<int> dp(level_sum.size(), 0);
        // if(level_sum.size() == 1) return level_sum[0];
        // dp[0] = level_sum[0];
        // dp[1] = max(dp[0], level_sum[1]);
        // for(int i = 2; i < level_sum.size(); ++i) {
        //     dp[i] = max(dp[i - 1], dp[i - 2] + level_sum[i]);
        // }
        // return dp[level_sum.size() - 1];

        // 动态规划优化
        int prev2 = 0, prev1 = level_sum[0];
        for (int i = 1; i < level_sum.size(); ++i) {
            int current = max(prev1, prev2 + level_sum[i]);
            prev2 = prev1;
            prev1 = current;
        }
        return prev1;
    }

    int s2_rob(TreeNode* root) {        // 递归优化
        static unordered_map<TreeNode*, int> umap;
        if(!root) return 0;
        if(root->left == nullptr && root->right == nullptr) return root->val;
        if(umap[root]) return umap[root];

        int val1 = root->val;
        if(root->left) val1 += s2_rob(root->left->left) + s2_rob(root->left->right);
        if(root->right) val1 += s2_rob(root->right->left) + s2_rob(root->right->right);

        int val2 = s2_rob(root->left) + s2_rob(root->right);
        umap[root] = max(val1, val2);
        return max(val1, val2);
    }
    int rob(TreeNode* root) {
        return s2_rob(root);
    }
};
// @lc code=end



/*
// @lcpr case=start
// [3,2,3,null,3,null,1]\n
// @lcpr case=end

// @lcpr case=start
// [3,4,5,1,3,null,1]\n
// @lcpr case=end

 */


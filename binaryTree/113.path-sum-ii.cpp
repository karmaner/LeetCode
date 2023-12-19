/*
 * @lc app=leetcode.cn id=113 lang=cpp
 * @lcpr version=30112
 *
 * [113] 路径总和 II
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
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution
{
public:
  void Backtracking(TreeNode* node,
                    vector<int>& path,
                    vector<vector<int>>& ans,
                    int targetSum)
  {
    path.push_back(node->val); // 中

    // 结束条件
    if (node->left == nullptr && node->right == nullptr) {
      int sum = 0;
      for (int i = 0; i < path.size(); i++) {
        sum += path[i];
      }
      if (sum == targetSum)
        ans.push_back(path);
    }

    // 递归左树
    if (node->left) { // 左
      Backtracking(node->left, path, ans, targetSum);
      path.pop_back(); // 回溯
    }

    // 递归右树
    if (node->right) { // 右
      Backtracking(node->right, path, ans, targetSum);
      path.pop_back(); // 回溯
    }
    return;
  }
  vector<vector<int>> pathSum(TreeNode* root, int targetSum)
  {

    vector<int> path;
    vector<vector<int>> ans;

    if (root == nullptr)
      return ans;
    Backtracking(root, path, ans, targetSum);
    return ans;
  }
};
// @lc code=end

/*
// @lcpr case=start
// [5,4,8,11,null,13,4,7,2,null,null,5,1]\n22\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3]\n5\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n0\n
// @lcpr case=end

 */

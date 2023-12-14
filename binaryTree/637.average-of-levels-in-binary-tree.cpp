/*
 * @lc app=leetcode.cn id=637 lang=cpp
 * @lcpr version=30111
 *
 * [637] 二叉树的层平均值
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
  vector<double> averageOfLevels(TreeNode* root)
  {
    // 辅助队列快速求解
    queue<TreeNode*> que;
    vector<double> result;
    if (root != nullptr)
      que.push(root);
    while (!que.empty()) {
      int size = que.size();
      long long sum = 0;
      for (int i = 0; i < size; i++) { // 每次确定一个层次的数据
        TreeNode* node = que.front();
        que.pop();
        sum += node->val;
        if (node->left)
          que.push(node->left);
        if (node->right)
          que.push(node->right);
      }
      result.push_back(sum * 1.0 / size);
    }
    return result;
  }
};
// @lc code=end

/*
// @lcpr case=start
// [3,9,20,null,null,15,7]\n
// @lcpr case=end

// @lcpr case=start
// [3,9,20,15,7]\n
// @lcpr case=end

 */

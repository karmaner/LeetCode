/*
 * @lc app=leetcode.cn id=104 lang=cpp
 * @lcpr version=30111
 *
 * [104] 二叉树的最大深度
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
  // 递归求深度
  int getDepth(TreeNode* node)
  {
    if (node == nullptr)
      return 0;
    int left = getDepth(node->left);
    int right = getDepth(node->right);
    return max(left, right) + 1;
  }
  int maxDepth(TreeNode* root)
  {

    return getDepth(root);
    // // 层次遍历求深度
    // queue<TreeNode*> que;

    // if (root != nullptr)
    //   que.push(root);
    // int depth = 0;
    // while (!que.empty()) {
    //   int size = que.size();
    //   depth++;
    //   for (int i = 0; i < size; i++) {
    //     TreeNode* node = que.front();
    //     que.pop();
    //     if (node->left)
    //       que.push(node->left);
    //     if (node->right)
    //       que.push(node->right);
    //   }
    // }
    // return depth;
  }
};
// @lc code=end

/*
// @lcpr case=start
// [3,9,20,null,null,15,7]\n
// @lcpr case=end

// @lcpr case=start
// [1,null,2]\n
// @lcpr case=end

 */

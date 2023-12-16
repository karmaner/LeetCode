/*
 * @lc app=leetcode.cn id=111 lang=cpp
 * @lcpr version=30111
 *
 * [111] 二叉树的最小深度
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
  int getMinDepth(TreeNode* node)
  {
    if (node == NULL)
      return 0;
    int leftDepth = getMinDepth(node->left);   // 左
    int rightDepth = getMinDepth(node->right); // 右
                                               // 中
    // 当一个左子树为空，右不为空，这时并不是最低点
    if (node->left == NULL && node->right != NULL) {
      return 1 + rightDepth;
    }
    // 当一个右子树为空，左不为空，这时并不是最低点
    if (node->left != NULL && node->right == NULL) {
      return 1 + leftDepth;
    }
    int result = 1 + min(leftDepth, rightDepth);
    return result;
  }
  int minDepth(TreeNode* root)
  {
    return getMinDepth(root);
    // // 层次遍历求解 二叉树深度
    // queue<TreeNode*> que;
    // int depth = 0;
    // if (root != nullptr)
    //   que.push(root);

    // while (!que.empty()) {
    //   int size = que.size();
    //   depth++;
    //   for (int i = 0; i < size; i++) {
    //     TreeNode* node = que.front();
    //     que.pop();

    //     if (!node->left && !node->right)
    //       return depth;
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
// [2,null,3,null,4,null,5,null,6]\n
// @lcpr case=end

 */

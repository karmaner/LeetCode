/*
 * @lc app=leetcode.cn id=101 lang=cpp
 * @lcpr version=30111
 *
 * [101] 对称二叉树
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
  /* 非递归求解这题
    层次遍历 比较左右子树
    思路是错误的  比如eg2这两颗树的层级遍历结果是一样的
    但是不是对称二叉树

    来自代码随想录  其实要比较就是比较两颗二叉树是否一样
    左子树 和 右子树 左子树的左侧 等于 右子树的右侧
    左子树的右侧 等于 右子树的左侧（外侧，内测）
    如果一样就是一样的二叉树，就是结构一样的二叉树 */
public:
  bool compare(TreeNode* left, TreeNode* right)
  {
    if (left == nullptr && right == nullptr)
      return true;
    else if (left != nullptr && right == nullptr)
      return false;
    else if (left == nullptr && right != nullptr)
      return false;
    else if (left->val != right->val)
      return false;

    bool outside = compare(left->left, right->right); // 外侧
    bool inside = compare(left->right, right->left);  // 内侧

    return outside && inside;
  }
  bool isSymmetric(TreeNode* root)
  {
    if (root == nullptr)
      return true;
    return compare(root->left, root->right);
  }
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,2,3,4,4,3]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,2,null,3,null,3]\n
// @lcpr case=end

 */

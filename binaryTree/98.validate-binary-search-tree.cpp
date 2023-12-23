/*
 * @lc app=leetcode.cn id=98 lang=cpp
 * @lcpr version=30112
 *
 * [98] 验证二叉搜索树
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
  void Inorder(TreeNode* root, vector<int>& ans)
  {
    if (root == nullptr)
      return;

    Inorder(root->left, ans);
    ans.push_back(root->val);
    Inorder(root->right, ans);
  }

  TreeNode* pre = nullptr;
  bool isValidBST(TreeNode* root)
  {

    if (root == nullptr)
      return true;
    bool left = isValidBST(root->left);

    if (pre != nullptr && pre->val >= root->val)
      return false;
    pre = root;
    bool right = isValidBST(root->right);

    return left && right;
    // // 错误写法 每一颗儿树是 但合在一起不一定是
    // if (root == nullptr)
    //   return true;
    // bool left = isValidBST(root->left);
    // bool right = isValidBST(root->right);

    // if (!root->left && !root->right) {
    //   return true;
    // } else if (!root->left && root->right && root->right->val > root->val) {
    //   return true;
    // } else if (root->left && !root->right && root->left->val < root->val) {
    //   return true;
    // } else if (root->left && root->right && root->val > root->left->val &&
    //            root->right->val > root->val) {
    //   return true;
    // } else {
    //   return false;
    // }
    // return left && right;

    // // 思路二
    // // 二叉搜索树的 中序结果是一个有序数值

    // vector<int> ans;
    // Inorder(root, ans);

    // for (int i = 1; i < ans.size(); i++) {
    //   if (ans[i] <= ans[i - 1])
    //     return false;
    // }
    // return true;

    // 思路三  中序遍历就
  }
};
// @lc code=end

/*
// @lcpr case=start
// [2,1,3]\n
// @lcpr case=end

// @lcpr case=start
// [5,1,4,null,null,3,6]\n
// @lcpr case=end

 */

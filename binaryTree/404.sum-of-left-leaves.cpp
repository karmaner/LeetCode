/*
 * @lc app=leetcode.cn id=404 lang=cpp
 * @lcpr version=30112
 *
 * [404] 左叶子之和
 */

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
  /* 一次递归解决问题 我写的 */
  // void getNodeSum(TreeNode* node, int& ans)
  // {
  //   if (node == nullptr)
  //     return;
  //   if (node->left) {
  //     getNodeSum(node->left, ans);
  //     if (node->left->left == nullptr && node->left->right == nullptr)
  //       ans += node->left->val;
  //   }
  //   if (node->right)
  //     getNodeSum(node->right, ans);
  // }
  int sumOfLeftLeaves(TreeNode* root)
  {
    // int ans = 0;
    // getNodeSum(root, ans);
    // return ans;

    /* 自己写法 */
    if (root == nullptr)
      return 0;
    if (root->left == nullptr && root->right == nullptr)
      return 0;

    int leftValue = sumOfLeftLeaves(root->left); // 左
    if (root->left && !root->left->left &&
        !root->left->right) { // 左子树就是一个左叶子的情况
      leftValue = root->left->val;
    }
    int rightValue = sumOfLeftLeaves(root->right); // 右

    int sum = leftValue + rightValue; // 中
    return sum;
  }
};
// @lc code=end

/*
// @lcpr case=start
// [3,9,20,null,null,15,7]\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

*/

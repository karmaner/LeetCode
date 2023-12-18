/*
 * @lc app=leetcode.cn id=110 lang=cpp
 * @lcpr version=30112
 *
 * [110] 平衡二叉树
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
  /* 递归访问 递归一定要明确结束条件 和需要输入的值和输出的值 */
  int getHeight(TreeNode* node)
  {
    if (!node)
      return 0;

    int leftHeight = getHeight(node->left);
    if (leftHeight == -1)
      return -1;
    int rightHeight = getHeight(node->right);
    if (rightHeight == -1)
      return -1;

    return abs(leftHeight - rightHeight) > 1 ? -1
                                             : 1 + max(leftHeight, rightHeight);
  }
  bool isBalanced(TreeNode* root)
  {
    return getHeight(root) == -1 ? false : true;
  }
};
// @lc code=end

/*
// @lcpr case=start
// [3,9,20,null,null,15,7]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,2,3,3,null,null,4,4]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

 */

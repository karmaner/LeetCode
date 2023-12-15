/*
 * @lc app=leetcode.cn id=226 lang=cpp
 * @lcpr version=30111
 *
 * [226] 翻转二叉树
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
  /* 这道题目看似很难，因为刚开始伙是这样想胡
      不就是交换一下左右孩纸吗， 但是看到eg1里面 9和1换了就打消国想法
      其实这个思路是对的 只不过每个孩纸都得翻转

      这题前序，后序，层次遍历都可以做 */
public:
  void preOrder(TreeNode* root)
  {
    if (root == nullptr)
      return;
    swap(root->left, root->right);
    preOrder(root->left);
    preOrder(root->right);
  }
  TreeNode* invertTree(TreeNode* root)
  {
    preOrder(root);
    return root;
  }
};
// @lc code=end

/*
// @lcpr case=start
// [4,2,7,1,3,6,9]\n
// @lcpr case=end

// @lcpr case=start
// [2,1,3]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

 */

/*
 * @lc app=leetcode.cn id=701 lang=cpp
 * @lcpr version=30112
 *
 * [701] 二叉搜索树中的插入操作
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
private:
  TreeNode* parent;
  void traversal(TreeNode* cur, int val)
  {
    if (cur == NULL) {
      TreeNode* node = new TreeNode(val);
      if (val > parent->val)
        parent->right = node;
      else
        parent->left = node;
      return;
    }
    parent = cur;
    if (cur->val > val)
      traversal(cur->left, val);
    if (cur->val < val)
      traversal(cur->right, val);
    return;
  }

public:
  TreeNode* insertIntoBST(TreeNode* root, int val)
  {
    parent = new TreeNode(0);
    if (root == NULL) {
      root = new TreeNode(val);
    }
    traversal(root, val);
    return root;
  }
};
// @lc code=end

/*
// @lcpr case=start
// [4,2,7,1,3]\n5\n
// @lcpr case=end

// @lcpr case=start
// [40,20,60,10,30,50,70]\n25\n
// @lcpr case=end

// @lcpr case=start
// [4,2,7,1,3,null,null,null,null,null,null]\n5\n
// @lcpr case=end

 */

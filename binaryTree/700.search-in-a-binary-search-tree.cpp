// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=700 lang=cpp
 * @lcpr version=30112
 *
 * [700] 二叉搜索树中的搜索
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
  TreeNode* searchBST(TreeNode* root, int val)
  {

    // if (root == NULL || root->val == val)
    //   return root;
    // if (root->val > val)
    //   return searchBST(root->left, val);
    // if (root->val < val)
    //   return searchBST(root->right, val);
    // return NULL;

    // 迭代
    while (root != nullptr) {
      if (val > root->val)
        root = root->right;
      else if (val < root->val)
        root = root->left;
      else
        return root;
    }
    return nullptr;
  }
};
// @lc code=end

/*
// @lcpr case=start
// [4,2,7,1,3]\n2\n
// @lcpr case=end

// @lcpr case=start
// [4,2,7,1,3]\n5\n
// @lcpr case=end

 */

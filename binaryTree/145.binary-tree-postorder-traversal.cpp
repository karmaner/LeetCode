/*
 * @lc app=leetcode.cn id=145 lang=cpp
 * @lcpr version=30111
 *
 * [145] 二叉树的后序遍历
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
  // /* 递归写法 */
  // void Traversal(TreeNode* root, vector<int>& nums)
  // {
  //   if (root == nullptr)
  //     return;
  //   if (root->left)
  //     Traversal(root->left, nums);
  //   if (root->right)
  //     Traversal(root->right, nums);
  //   nums.push_back(root->val);
  // }
  vector<int> postorderTraversal(TreeNode* root)
  {
    // vector<int> ans;
    // Traversal(root, ans);
    // return ans;

    /* 迭代写法 */
    stack<TreeNode*> st;
    vector<int> result;
    if (root != nullptr)
      st.push(root);
    while (!st.empty()) {
      TreeNode* node = st.top();
      if (node != nullptr) {
        st.pop();
        st.push(node);
        st.push(nullptr);

        if (node->right)
          st.push(node->right);

        if (node->left)
          st.push(node->left);

      } else {
        st.pop();
        node = st.top();
        result.push_back(node->val);
        st.pop();
      }
    }
    return result;
  }
};
// @lc code=end

/*
// @lcpr case=start
// [1,null,2,3]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

 */

/*
 * @lc app=leetcode.cn id=144 lang=cpp
 * @lcpr version=30111
 *
 * [144] 二叉树的前序遍历
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
  //  vector<int> ans;  // 版本一

  // /* 版本二 */
  // void Traversal(TreeNode* root, vector<int>& nums)
  // {
  //   if (root == nullptr)
  //     return;
  //   nums.push_back(root->val);
  //   if (root->left)
  //     Traversal(root->left, nums);
  //   if (root->right)
  //     Traversal(root->right, nums);
  // }
  vector<int> preorderTraversal(TreeNode* root)
  {
    // // 递归遍历

    // if (root == nullptr)
    //   return {};
    // else {
    //   ans.push_back(root->val);
    //   preorderTraversal(root->left);
    //   preorderTraversal(root->right);
    // }
    // return ans;

    // // 2 优化 以后时间打败多
    // vector<int> ans;
    // Traversal(root, ans);
    // return ans;

    // 非递归写法  即迭代写法  前序遍历(先根遍历)
    // stack<TreeNode*> st;
    // vector<int> result;
    // if (root == nullptr)
    //   return result;
    // st.push(root);

    // while (!st.empty()) {
    //   TreeNode* node = st.top();
    //   st.pop();
    //   result.push_back(node->val);
    //   if (node->right)
    //     st.push(node->right);
    //   if (node->left)
    //     st.push(node->left);
    // }
    // return result;

    // 统一风格写法
    vector<int> result;
    stack<TreeNode*> st;

    if (root != nullptr)
      st.push(root);
    while (!st.empty()) {
      TreeNode* node = st.top();
      if (node != nullptr) {
        st.pop();
        if (node->right)
          st.push(node->right);
        if (node->left)
          st.push(node->left);

        /* 标记使用 两次pop 遇到null 就是数据输出 */
        st.push(node);
        st.push(nullptr);
      } else {
        st.pop();
        node = st.top();
        st.pop();
        result.push_back(node->val);
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

// @lcpr case=start
// [1,2]\n
// @lcpr case=end

// @lcpr case=start
// [1,null,2]\n
// @lcpr case=end

 */

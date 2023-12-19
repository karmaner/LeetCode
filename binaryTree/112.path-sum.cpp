// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=112 lang=cpp
 * @lcpr version=30112
 *
 * [112] 路径总和
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
  // /* 其实这个写法会过于冗余 比如每一个根节点到叶子节点都得计算 */
  // // 第一种写法
  // void Backtracking(TreeNode* node, vector<int>& path, vector<int>& nums)
  // {
  //   path.push_back(node->val); // 中

  //   // 结束条件
  //   if (node->left == nullptr && node->right == nullptr) {
  //     int sum = 0;
  //     for (int i = 0; i < path.size(); i++) {
  //       sum += path[i];
  //     }
  //     nums.push_back(sum);
  //   }

  //   // 递归左树
  //   if (node->left) { // 左
  //     Backtracking(node->left, path, nums);
  //     path.pop_back(); // 回溯
  //   }

  //   // 递归右树
  //   if (node->right) { // 右
  //     Backtracking(node->right, path, nums);
  //     path.pop_back(); // 回溯
  //   }
  //   return;
  // }

  // 部分递归
  // bool isSum(TreeNode* node, int sum)
  // {
  //   if (node->left == nullptr && node->right == nullptr && sum == 0)
  //     return true;
  //   if (node->left == nullptr && node->right == nullptr)
  //     return false;

  //   if (node->left) {         // 左
  //     sum -= node->left->val; // 递归，处理节点;
  //     if (isSum(node->left, sum))
  //       return true;
  //     sum += node->left->val; // 回溯，撤销处理结果
  //   }
  //   if (node->right) {         // 右
  //     sum -= node->right->val; // 递归，处理节点;
  //     if (isSum(node->right, sum))
  //       return true;
  //     sum += node->right->val; // 回溯，撤销处理结果
  //   }
  //   return false;
  // }

  bool hasPathSum(TreeNode* root, int targetSum)
  {
    // // 第一种写法
    // vector<int> path;
    // vector<int> ans;
    // if (root == nullptr)
    //   return false;
    // Backtracking(root, path, ans);

    // // 找目标值
    // for (int i = 0; i < ans.size(); i++) {
    //   if (ans[i] == targetSum)
    //     return true;
    // }
    // return false;

    // // 这是部分递归  减少了无用时间的部分。
    // if (root == nullptr)
    //   return false;
    // return isSum(root, targetSum - root->val);

    // 使用栈模拟递归
    if (root == nullptr)
      return false;

    // 此时栈里要放的是pair<节点指针，路径数值>
    stack<pair<TreeNode*, int>> st;
    st.push(pair<TreeNode*, int>(root, root->val));

    while (!st.empty()) {
      pair<TreeNode*, int> node = st.top();
      st.pop();

      if (node.first->left == nullptr && node.first->right == nullptr &&
          node.second == targetSum)
        return true;

      if (node.first->right)
        st.push(pair<TreeNode*, int>(node.first->right,
                                     node.second + node.first->right->val));
      // 左节点，压进去一个节点的时候，将该节点的路径数值也记录下来
      if (node.first->left) {
        st.push(pair<TreeNode*, int>(node.first->left,
                                     node.second + node.first->left->val));
      }
    }
    return false;
  }
};
// @lc code=end

/*
// @lcpr case=start
// [5,4,8,11,null,13,4,7,2,null,null,null,1]\n22\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3]\n5\n
// @lcpr case=end

// @lcpr case=start
// []\n0\n
// @lcpr case=end

 */

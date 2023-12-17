/*
 * @lc app=leetcode.cn id=222 lang=cpp
 * @lcpr version=30111
 *
 * [222] 完全二叉树的节点个数
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
  // /* 递归遍历 */
  // int getNodeNum(TreeNode* node)
  // {
  //   if (!node)
  //     return 0;
  //   int left = getNodeNum(node->left);
  //   int right = getNodeNum(node->right);

  //   return 1 + left + right;
  // }

  /* 迭代遍历 */
  int countNodes(TreeNode* root)
  {
    // return getNodeNum(root);

    queue<TreeNode*> que;
    int result = 0;
    if (root)
      que.push(root);
    while (!que.empty()) {
      int size = que.size();
      result += size;
      for (int i = 0; i < size; i++) {
        TreeNode* node = que.front();
        que.pop();
        if (node->left)
          que.push(node->left);
        if (node->right)
          que.push(node->right);
      }
    }
    return result;
  }
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,3,4,5,6]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

 */

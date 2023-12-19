/*
 * @lc app=leetcode.cn id=513 lang=cpp
 * @lcpr version=30112
 *
 * [513] 找树左下角的值
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
  /* 递归一点都不好理解 还得是层次遍历 */
  // int maxDepth = INT_MIN;
  // int result;
  // void traversal(TreeNode* root, int depth)
  // {
  //   if (root->left == NULL && root->right == NULL) {
  //     if (depth > maxDepth) {
  //       maxDepth = depth;
  //       result = root->val;
  //     }
  //     return;
  //   }
  //   if (root->left) {
  //     depth++;
  //     traversal(root->left, depth);
  //     depth--; // 回溯
  //   }
  //   if (root->right) {
  //     depth++;
  //     traversal(root->right, depth);
  //     depth--; // 回溯
  //   }
  //   return;
  // }
  int findBottomLeftValue(TreeNode* root)
  {
    // traversal(root, 0);
    // return result;
    queue<TreeNode*> que;
    int ans = 0;

    if (root != nullptr)
      que.push(root);
    while (!que.empty()) {
      int size = que.size();

      for (int i = 0; i < size; i++) {
        TreeNode* node = que.front();
        que.pop();

        if (node->left)
          que.push(node->left);

        if (node->right)
          que.push(node->right);

        if (i == 0)
          ans = node->val;
      }
    }
    return ans;
  }
};
// @lc code=end

/*
// @lcpr case=start
// [2,1,3]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4,null,5,6,null,null,7]\n
// @lcpr case=end

 */

/*
 * @lc app=leetcode.cn id=257 lang=cpp
 * @lcpr version=30112
 *
 * [257] 二叉树的所有路径
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
  /* 本题需要使用前序遍历 为什么-》 因为是要根节点指向叶子节点 */
public:
  void getPath(TreeNode* node, vector<int>& path, vector<string>& ans)
  {

    path.push_back(node->val); // 中

    /* 递归结束条件 */
    if (node->left == nullptr && node->right == nullptr) {
      string temp = to_string(path[0]);
      for (int i = 1; i < path.size(); ++i) {
        temp += "->";
        temp += to_string(path[i]);
      }
      ans.push_back(temp);
      return;
    }

    if (node->left) {
      getPath(node->left, path, ans);
      path.pop_back(); // 回溯
    }

    if (node->right) {
      getPath(node->right, path, ans);
      path.pop_back(); // 回溯
    }
    return;
  }
  vector<string> binaryTreePaths(TreeNode* root)
  {
    vector<int> path;
    vector<string> ans;
    if (!root)
      return ans;
    getPath(root, path, ans);
    return ans;
  }
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,3,null,5]\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

 */

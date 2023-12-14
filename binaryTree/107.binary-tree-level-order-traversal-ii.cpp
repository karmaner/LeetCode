/*
 * @lc app=leetcode.cn id=107 lang=cpp
 * @lcpr version=30111
 *
 * [107] 二叉树的层序遍历 II
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
  vector<vector<int>> levelOrderBottom(TreeNode* root)
  {
    // 1.层次遍历 然后翻转数据
    // 2.每次层次编辑的结果用栈存储

    queue<TreeNode*> que;
    stack<vector<int>> st;
    if (root != nullptr)
      que.push(root);
    vector<vector<int>> result;
    while (!que.empty()) {
      int size = que.size(); // 定义高度  出去一个加入两个所以是高度
      vector<int> vec;
      for (int i = 0; i < size; i++) {
        TreeNode* node = que.front();
        que.pop();
        vec.push_back(node->val);
        if (node->left)
          que.push(node->left);
        if (node->right)
          que.push(node->right);
      }
      st.push(vec);
    }
    while (!st.empty()) {
      result.push_back(st.top());
      st.pop();
    }
    // reverse(result.begin(), result.end()); // 法一
    return result;
  }
};
// @lc code=end

/*
// @lcpr case=start
// [3,9,20,null,null,15,7]\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

 */

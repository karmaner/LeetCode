/*
 * @lc app=leetcode.cn id=100 lang=cpp
 * @lcpr version=30111
 *
 * [100] 相同的树
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
  /* 上一题用的递归  这题就用一用  迭代  使用辅助队列实现吧 */
  /* 递归再来跑一次吧 */
public:
  bool compare(TreeNode* left, TreeNode* right)
  {
    if (left == nullptr && right == nullptr)
      return true;
    else if (left != nullptr && right == nullptr)
      return false;
    else if (left == nullptr && right != nullptr)
      return false;
    else if (left->val != right->val)
      return false;

    bool outside = compare(left->left, right->left);
    bool inside = compare(left->right, right->right);
    return inside && outside;
  }
  bool isSameTree(TreeNode* p, TreeNode* q)
  {
    // 递归求解
    return compare(p, q);

    // queue<TreeNode*> que;
    // que.push(p); // 将左子树头结点加入队列
    // que.push(q); // 将右子树头结点加入队列
    // while (!que.empty()) {
    //   TreeNode* leftNode = que.front();
    //   que.pop();
    //   TreeNode* rightNode = que.front();
    //   que.pop();

    //   if (leftNode == nullptr && rightNode == nullptr) // 相等
    //     continue;
    //   if ((!leftNode && rightNode) || (leftNode && !rightNode) ||
    //       (leftNode->val != rightNode->val))
    //     return false;

    //   que.push(leftNode->left);
    //   que.push(rightNode->left);
    //   que.push(leftNode->right);
    //   que.push(rightNode->right);
    // }
    // return true;
  }
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,3]\n[1,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n[1,null,2]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,1]\n[1,1,2]\n
// @lcpr case=end

 */

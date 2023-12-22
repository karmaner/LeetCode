/*
 * @lc app=leetcode.cn id=106 lang=cpp
 * @lcpr version=30112
 *
 * [106] 从中序与后序遍历序列构造二叉树
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
  TreeNode* traversal(vector<int>& inorder, vector<int>& postorder)
  {

    // 第一步
    if (postorder.size() == 0)
      return NULL;

    // 第二步：后序遍历数组最后一个元素，就是当前的中间节点
    int rootValue = postorder[postorder.size() - 1];
    TreeNode* root = new TreeNode(rootValue);

    // 叶子节点
    if (postorder.size() == 1)
      return root;

    // 第三步：找切割点
    int delimiterIndex;
    for (delimiterIndex = 0; delimiterIndex < inorder.size();
         delimiterIndex++) {
      if (inorder[delimiterIndex] == rootValue)
        break;
    }

    // vector构造函数为左闭右开

    // 第四步：切割中序数组，得到 中序左数组和中序右数组
    vector<int> leftInOrder(inorder.begin(), inorder.begin() + delimiterIndex);
    vector<int> rightInOrder(inorder.begin() + delimiterIndex + 1,
                             inorder.end());

    // 根据元素大小来进行切割
    // 第五步：切割后序数组，得到 后序左数组和后序右数组
    vector<int> leftPostOrder(postorder.begin(),
                              postorder.begin() + leftInOrder.size());
    vector<int> rightPostOrder(postorder.begin() + leftInOrder.size(),
                               postorder.end() - 1);

    // 第六步
    root->left = traversal(leftInOrder, leftPostOrder);
    root->right = traversal(rightInOrder, rightPostOrder);

    return root;
  }
  TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
  {
    if (inorder.size() == 0 || postorder.size() == 0)
      return nullptr;
    return traversal(inorder, postorder);
  }
};
// @lc code=end

/*
// @lcpr case=start
// [9,3,15,20,7]\n[9,15,7,20,3]\n
// @lcpr case=end

// @lcpr case=start
// [-1]\n[-1]\n
// @lcpr case=end

 */

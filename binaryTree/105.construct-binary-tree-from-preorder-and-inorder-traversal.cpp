/*
 * @lc app=leetcode.cn id=105 lang=cpp
 * @lcpr version=30112
 *
 * [105] 从前序与中序遍历序列构造二叉树
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
  TreeNode* traversal(vector<int>& preorder, vector<int>& inorder)
  {

    // 第一步
    if (preorder.size() == 0)
      return nullptr;

    // 第二步：后序遍历数组最后一个元素，就是当前的中间节点
    int rootValue = preorder[0];
    TreeNode* root = new TreeNode(rootValue);

    // 叶子节点
    if (preorder.size() == 1)
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
    // 第五步：切割前序数组，得到 前序左数组和前序右数组
    vector<int> leftPreOrder(preorder.begin() + 1,
                             preorder.begin() + 1 + leftInOrder.size());
    vector<int> rightPreOrder(preorder.begin() + 1 + leftInOrder.size(),
                              preorder.end());

    // 第六步
    root->left = traversal(leftPreOrder, leftInOrder);
    root->right = traversal(rightPreOrder, rightInOrder);

    return root;
  }
  TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
  {
    if (preorder.size() == 0 || inorder.size() == 0)
      return nullptr;
    return traversal(preorder, inorder);
  }
};
// @lc code=end

/*
// @lcpr case=start
// [3,9,20,15,7]\n[9,3,15,20,7]\n
// @lcpr case=end

// @lcpr case=start
// [-1]\n[-1]\n
// @lcpr case=end

 */

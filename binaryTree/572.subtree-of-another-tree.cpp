/*
 * @lc app=leetcode.cn id=572 lang=cpp
 * @lcpr version=30111
 *
 * [572] 另一棵树的子树
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
  bool isSameTree(TreeNode* p, TreeNode* q)
  {
    if (p == nullptr && q == nullptr)
      return true;
    if (p && q && p->val == q->val)
      return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    else
      return false;
  }
  bool isSubtree(TreeNode* root, TreeNode* subRoot)
  {
    if (!root) // root不可能走到空
      return false;

    if (isSameTree(root, subRoot))
      return true;

    return isSubtree(root->left, subRoot) ||
           isSubtree(root->right,
                     subRoot); // 左边为真就不用求右边了，所以是或关系
  }
};
// @lc code=end

/*
// @lcpr case=start
// [3,4,5,1,2]\n[4,1,2]\n
// @lcpr case=end

// @lcpr case=start
// [3,4,5,1,2,null,null,null,null,0]\n[4,1,2]\n
// @lcpr case=end

 */

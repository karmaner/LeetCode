/*
 * @lc app=leetcode.cn id=654 lang=cpp
 * @lcpr version=30112
 *
 * [654] 最大二叉树
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
  int findBigest(vector<int>& nums)
  {
    int index = -1;
    int max = INT_MIN;
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] > max) {
        index = i;
        max = nums[i];
      }
    }
    return index;
  }
  TreeNode* bigTree(vector<int>& nums)
  {
    int cut = findBigest(nums);
    if (cut == -1)
      return nullptr;
    int rootValue = nums[cut];
    TreeNode* root = new TreeNode(rootValue);

    vector<int> left(nums.begin(), nums.begin() + cut);
    vector<int> right(nums.begin() + cut + 1, nums.end());

    root->left = bigTree(left);
    root->right = bigTree(right);

    return root;
  }
  TreeNode* constructMaximumBinaryTree(vector<int>& nums)
  {
    if (nums.size() == 0)
      return nullptr;
    return bigTree(nums);
  }
};
// @lc code=end

/*
// @lcpr case=start
// [3,2,1,6,0,5]\n
// @lcpr case=end

// @lcpr case=start
// [3,2,1]\n
// @lcpr case=end

 */

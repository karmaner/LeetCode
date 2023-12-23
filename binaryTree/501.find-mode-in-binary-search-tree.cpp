/*
 * @lc app=leetcode.cn id=501 lang=cpp
 * @lcpr version=30112
 *
 * [501] 二叉搜索树中的众数
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
private:
  unordered_map<int, int> map;
  void searchBST(TreeNode* cur, unordered_map<int, int>& map)
  {
    if (cur == nullptr)
      return;
    map[cur->val]++;
    searchBST(cur->left, map);
    searchBST(cur->right, map);
  }

public:
  vector<int> findMode(TreeNode* root)
  {
    searchBST(root, map);
    vector<int> ans;
    int max = INT_MIN;
    int num = 0;
    for (auto s : map) {
      if (s.second > max) {
        max = s.second;
      }
    }
    for (auto s : map) {
      if (s.second == max)
        ans.push_back(s.first);
    }
    return ans;
  }
};
// @lc code=end

/*
// @lcpr case=start
// [1,null,2,2]\n
// @lcpr case=end

// @lcpr case=start
// [0]\n
// @lcpr case=end

 */

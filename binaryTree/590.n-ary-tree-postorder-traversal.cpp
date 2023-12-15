/*
 * @lc app=leetcode.cn id=590 lang=cpp
 * @lcpr version=30111
 *
 * [590] N 叉树的后序遍历
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
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution
{
public:
  vector<int> postorder(Node* root)
  {
    stack<Node*> st;
    vector<int> result;
    if (root != nullptr)
      st.push(root);
    while (!st.empty()) {
      Node* node = st.top();
      if (node != nullptr) {
        st.pop();

        st.push(node);
        st.push(nullptr);

        for (int i = node->children.size() - 1; i >= 0; --i) {
          if (node->children[i])
            st.push(node->children[i]);
        }

      } else { // output
        st.pop();
        node = st.top();
        st.pop();
        result.push_back(node->val);
      }
    }
    return result;
  }
};

// @lc code=end

/*
// @lcpr case=start
// [1,null,3,2,4,null,5,6]\n
// @lcpr case=end

// @lcpr case=start
//
[1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]\n
// @lcpr case=end

 */

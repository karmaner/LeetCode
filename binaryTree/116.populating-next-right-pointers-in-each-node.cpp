/*
 * @lc app=leetcode.cn id=116 lang=cpp
 * @lcpr version=30111
 *
 * [116] 填充每个节点的下一个右侧节点指针
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
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution
{
public:
  Node* connect(Node* root)
  {
    queue<Node*> que;
    if (root != NULL)
      que.push(root);
    while (!que.empty()) {
      int size = que.size();
      // vector<int> vec;
      Node* nodePre;
      Node* node;
      for (int i = 0; i < size; i++) {
        if (i == 0) {
          nodePre = que.front(); // 取出一层的头结点
          que.pop();
          node = nodePre;
        } else {
          node = que.front();
          que.pop();
          nodePre->next = node; // 本层前一个节点next指向本节点
          nodePre = nodePre->next;
        }
        if (node->left)
          que.push(node->left);
        if (node->right)
          que.push(node->right);
      }
      nodePre->next = NULL; // 本层最后一个节点指向NULL
    }
    return root;
  }
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,3,4,5,6,7]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

 */

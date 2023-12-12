// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=150 lang=cpp
 * @lcpr version=30111
 *
 * [150] 逆波兰表达式求值
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
class Solution {
 public:
  int evalRPN(vector<string> &tokens) {
    // 遇到符号就计算 并且 把结果压入栈内
    stack<int> st;
    int op1 = 0, op2 = 0;
    for (auto s : tokens) {
      if (s == "+") {
        op1 = st.top();
        st.pop();
        op2 = st.top();
        st.pop();
        st.push(op1 + op2);
      } else if (s == "-") {
        op1 = st.top();
        st.pop();
        op2 = st.top();
        st.pop();
        st.push(op2 - op1);
      } else if (s == "*") {
        op1 = st.top();
        st.pop();
        op2 = st.top();
        st.pop();
        st.push(op2 * op1);
      } else if (s == "/") {
        op1 = st.top();
        st.pop();
        op2 = st.top();
        st.pop();
        st.push(op2 / op1);
      } else {  // 整数
        st.push(stoi(s));
      }
    }
    return st.top();
  }
};
// @lc code=end

/*
// @lcpr case=start
// ["2","1","+","3","*"]\n
// @lcpr case=end

// @lcpr case=start
// ["4","13","5","/","+"]\n
// @lcpr case=end

// @lcpr case=start
// ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]\n
// @lcpr case=end

 */

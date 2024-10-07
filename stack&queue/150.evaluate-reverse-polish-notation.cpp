/*
 * @lc app=leetcode.cn id=150 lang=cpp
 * @lcpr version=30204
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
#define XX(op) \
    int num1 = ans.top(); \
    ans.pop(); \
    int num2 = ans.top(); \
    ans.pop(); \
    ans.push(num2 op num1); 
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> ans;
        for(auto s : tokens) {
            if(s == "+") {
                XX(+);
            } else if(s == "-") {
                XX(-);
            } else if(s == "*") {
                XX(*);
            } else if(s == "/") {
                XX(/);
            } else {
                int num = std::stoi(s);
                ans.push(num);
            }
        }
        return ans.top();
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


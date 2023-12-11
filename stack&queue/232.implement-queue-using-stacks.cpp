// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=232 lang=cpp
 * @lcpr version=30111
 *
 * [232] 用栈实现队列
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
class MyQueue
{
public:
    stack<int> In;
    stack<int> Out;
    int ans = 0;
    MyQueue()
    {
    }

    void push(int x)
    {
        In.push(x);
    }

    int pop()
    {
        if (Out.empty())
        {
            while (!In.empty())
            {
                Out.push(In.top());
                In.pop();
            }
            int ans = Out.top();
            Out.pop();
            return ans;
        }
        ans = Out.top();
        Out.pop();
        return ans;
    }

    int peek()
    {
        if (Out.empty())
        {
            while (!In.empty())
            {
                Out.push(In.top());
                In.pop();
            }
        }
        return Out.top();
    }

    bool empty()
    {
        return Out.empty() && In.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end

/*
// @lcpr case=start
// ["MyQueue", "push", "push", "peek", "pop", "empty"][[], [1], [2], [], [], []]\n
// @lcpr case=end

 */

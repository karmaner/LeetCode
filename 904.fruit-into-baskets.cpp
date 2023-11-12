/*
 * @lc app=leetcode.cn id=904 lang=cpp
 * @lcpr version=30109
 *
 * [904] 水果成篮
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
    // 暴力遍历数组  找出最大连续的两个字符长度
    int totalFruit(vector<int>& fruits) {

        int left = 0, cnt = 0, left_cnt = 0;
        queue<int> myqueue;


        myqueue.push(fruits[0]);
        int len = fruits.size();
        for (int i=0; i < len; ++i) {
            if (myqueue.size()<2 && fruits[i] != myqueue.front()) {
                myqueue.push(fruits[i]);
            }
            
            // 在队列中 更新队列中元素的位置
            if (myqueue.size() == 2 && fruits[i] != myqueue.back() && fruits[i] == myqueue.front()) {
                myqueue.pop();
                myqueue.push(fruits[i]);
            }

            // 不在队列中(有第三种字符) 1. 计算连续字符的长度 2. 队列更新 // 前提有三种字符及以上
            if (fruits[i] != myqueue.front() && fruits[i] != myqueue.back()) {
                int new_cnt = i - left;

                if (new_cnt > cnt) 
                    cnt = new_cnt;

                myqueue.pop();
                myqueue.push(fruits[i]);
                // 找到重复次数
                int j = i-1;
                int same_cnt = 1;
                while (fruits[--j] == myqueue.front()) {
                    ++same_cnt;
                };
                left = i - same_cnt;
                
            } 
        
        }
        // 处理只有一或二种水果的情况
        return max(cnt, len - left);

    }
};
// @lc code=end
int main() {
    vector<int> fruits = {1,0,1,4,1,4,1,2,3};
    // 不通过 0,1,6,6,4,4,6     添加循环因子通过

    // 不通过 1,0,1,4,1,4,1,2,3
    Solution s;
    int a = s.totalFruit(fruits);
    cout << a;
    return 0;
}


/*
// @lcpr case=start
// [1,2,1]\n
// @lcpr case=end

// @lcpr case=start
// [0,1,2,2]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,2,2]\n
// @lcpr case=end

// @lcpr case=start
// [3,3,3,1,2,1,1,2,3,3,4]\n
// @lcpr case=end

 */


// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=541 lang=cpp
 * @lcpr version=30204
 *
 * [541] 反转字符串 II
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
    template<typename T>
    void swap(T& a, T& b) {
        T temp = a;
        a = b;
        b = temp;
    }

    template<typename T>
    void reverse(int begin, int end, T& str) {  // 符合原著 end指向 当前结束字符的下一个
        while(begin < end) {
            swap(str[begin], str[end - 1]);
            begin++;
            end--;
        }
    }
public:
    string reverseStr(string s, int k) {
        int count = 0;
        for(int i = 0; i < s.size(); ++i) {
            count++;
            if(count == 2 * k) {
                reverse(i - 2 * k + 1, i - k + 1, s);   // 位置问题
                count = 0;
            }
        }
        if(count < k) {
            reverse(s.size() - count, s.size(), s);
        }

        if(count >= k && count < 2 * k) {
            int left = count % k;
            reverse(s.size() - count, s.size() - left, s);
        }
        return s;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "abcdefg"\n2\n
// @lcpr case=end

// @lcpr case=start
// "abcd"\n2\n
// @lcpr case=end

 */


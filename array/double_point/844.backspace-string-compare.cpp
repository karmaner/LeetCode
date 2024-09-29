/*
 * @lc app=leetcode.cn id=844 lang=cpp
 * @lcpr version=30204
 *
 * [844] 比较含退格的字符串
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
    string true_string(string str) {
        string to_str;      // 栈使用
        for(int fastIndex = 0; fastIndex < str.size(); fastIndex++) {
            if(str[fastIndex] == '#') {
                if(to_str.size())       // 退格过多
                    to_str.erase(to_str.size() - 1);
            } else {
                to_str.push_back(str[fastIndex]);
            }
        }
        return to_str;
    }

public:
    // 双指针
    string true_string_double_point(string str) {
        int size = str.size();
        int slow = 0;
        for(int fast = 0; fast < size; fast++) {
            if(str[fast] != '#') {
                str[slow++] = str[fast];
            } else {
                if(slow > 0) {
                    slow--;
                }
            }
        }
        return str.substr(0, slow); 
    }
public:
    bool backspaceCompare(string s, string t) {
        // string s1 = true_string(s);
        // string s2 = true_string(t);
        string s1 = true_string_double_point(s);
        string s2 = true_string_double_point(t);
        return s1 == s2;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "ab#c"\n"ad#c"\n
// @lcpr case=end

// @lcpr case=start
// "ab##"\n"c#d#"\n
// @lcpr case=end

// @lcpr case=start
// "a#c"\n"b"\n
// @lcpr case=end

 */


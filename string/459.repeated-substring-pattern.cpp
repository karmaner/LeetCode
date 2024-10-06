/*
 * @lc app=leetcode.cn id=459 lang=cpp
 * @lcpr version=30204
 *
 * [459] 重复的子字符串
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
    bool s1_repeatedSubstringPattern(string s) {    // 掐头去尾以后如果可以组成s就说明有重复
        string t = s + s;
        t.erase(t.begin()); t.erase(t.end() - 1); // 掐头去尾
        if (t.find(s) != std::string::npos) return true; // r
        return false;
    }

    vector<int> getNext(string s) {
        vector<int> next(s.size(), 0);
        int j = 0;  // 记录起始位置
        for(int i = 1; i < s.size(); i++) {
            while(j > 0 && s[i] != s[j]) {
                j = next[j - 1];
            }
            if (s[i] == s[j])
                j += 1;
            next[i] = j;
        }
        return next;
    }

    bool s2_repeatedSubstringPattern(string s) {
        int len = s.size();
        if(len == 0) return false;
        vector<int> next = getNext(s);

        int loop_str_len = next[next.size() - 1];
        return loop_str_len > 0 && len % (len - loop_str_len) == 0;
    }
public:
    bool repeatedSubstringPattern(string s) {   // kmp
        return s2_repeatedSubstringPattern(s);
    }
};
// @lc code=end



/*
// @lcpr case=start
// "abab"\n
// @lcpr case=end

// @lcpr case=start
// "aba"\n
// @lcpr case=end

// @lcpr case=start
// "abcabcabcabc"\n
// @lcpr case=end

 */


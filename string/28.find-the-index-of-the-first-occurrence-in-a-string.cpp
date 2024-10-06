/*
 * @lc app=leetcode.cn id=28 lang=cpp
 * @lcpr version=30204
 *
 * [28] 找出字符串中第一个匹配项的下标
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
    int s1_strStr(string haystack, string needle) { // 暴力匹配 回溯
        if(needle.size() > haystack.size()) return -1;

        for(int i = 0; i < haystack.size(); i++) {
            int j = 0, k = i;
            while(haystack[k++] == needle[j++]) {
                if(j == needle.size()) return i;
            }
        }
        return -1;
    }

    vector<int> getNext_1(string patt) {
        vector<int> next(0, patt.size());
        next[0] = 0;

        int prefix_len = 0; // 当前最长前后缀的长度 = 前缀需要匹配的位置
        int i = 1;
        while(i < patt.size()) {
            if(patt[prefix_len] == patt[i]) { // 最长前缀的下一位 和后缀的新添加的一位
                prefix_len++;
                next[i] = prefix_len;
                i++;
            } else {
                if(prefix_len == 0) {
                    next[i] = 0;
                    i++;
                } else {
                    prefix_len = next[prefix_len - 1];
                }
            }
        }
        return next;
    }

    vector<int> getNext(string patt) {
        vector<int> next(patt.size(), 0);
        int prefix_len = 0;

        for (int i = 1; i < patt.size(); ) {
            if (patt[prefix_len] == patt[i]) {
                next[i++] = ++prefix_len;
            } else if (prefix_len) {
                prefix_len = next[prefix_len - 1];
            } else {
                next[i++] = 0;
            }
        }
        return next;
    }


    int s2_strStr(string haystack, string needle) { // kmp匹配
        int n = haystack.size();
        int m = needle.size();
        vector<int> next = getNext(needle);

        int i = 0;
        int j = 0;
        while(i < n) {
            if(needle[j] == haystack[i]) {
                j++;
                i++;
            }
            if(j == m)  {
                return i - j;
            }
            if(i < n && needle[j] != haystack[i]) {
                if(j != 0) {
                    j = next[j - 1];
                } else {
                    i++;
                }
            }
        }
        return -1;
    }
public:
    int strStr(string haystack, string needle) {
        // return s1_strStr(haystack, needle);
        return s2_strStr(haystack, needle);
    }
};
// @lc code=end



/*
// @lcpr case=start
// "sadbutsad"\n"sad"\n
// @lcpr case=end

// @lcpr case=start
// "leetcode"\n"leeto"\n
// @lcpr case=end

 */


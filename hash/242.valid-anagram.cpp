/*
 * @lc app=leetcode.cn id=242 lang=cpp
 * @lcpr version=30204
 *
 * [242] 有效的字母异位词
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
    bool s1_isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;

        // unordered_map<char, int> maps;
        int maps[26];
        // unordered_map<char, int> mapt;
        int mapt[26];
        for(auto c : s) {
            maps[c - 'a']++;
        }
        for(auto c : t) {
            mapt[c - 'a']++;
        }
        for(auto c : s) {
            if(maps[c - 'a'] != mapt[c - 'a']) {
                return false;
            }
        }
        return true;
    }

    bool s2_isAnagram(string s, string t) { // 排序字符串
        if(s.size() != t.size()) return false;
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
    bool s3_isAnagram(string s, string t) {
        int map[26];
        for(auto c : s) {
            map[c - 'a']++;
        }
        for(auto c : t) {
            map[c - 'a']--;
        }
        for(auto i : map) {
            if(i != 0) return false;
        }
        return true;
    }
public:
    bool isAnagram(string s, string t) {
        // return s1_isAnagram(s, t);
        // return s2_isAnagram(s, t);
        return s3_isAnagram(s, t);
    }
};
// @lc code=end



/*
// @lcpr case=start
// "anagram"\n"nagaram"\n
// @lcpr case=end

// @lcpr case=start
// "rat"\n"car"\n
// @lcpr case=end

 */


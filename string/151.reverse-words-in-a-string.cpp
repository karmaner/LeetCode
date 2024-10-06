/*
 * @lc app=leetcode.cn id=151 lang=cpp
 * @lcpr version=30204
 *
 * [151] 反转字符串中的单词
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
    void removeExtraSpace(string& s) {
        for(int i = s.size() - 1; i > 0; --i) {
            if(s[i] == s[i - 1] && s[i] == ' ') {
                s.erase(s.begin() + i);
            }
        }

        if(s.size() > 0 && s[s.size() - 1] == ' ') {
            s.erase(s.begin() + s.size() - 1);
        }

        if(s.size() > 0 && s[0] == ' ') {
            s.erase(s.begin());
        }
    }
    string reverseWords(string s) {
        removeExtraSpace(s);
        reverse(s.begin(), s.end());
        
        int word_length = 0;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == ' ') {
                reverse(s.begin() + i - word_length, s.begin() + i);
                word_length = 0;
            } else {
                word_length++;
            }
        }
        reverse(s.end() - word_length, s.end());
        return s;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "the sky is blue"\n
// @lcpr case=end

// @lcpr case=start
// "  hello world  "\n
// @lcpr case=end

// @lcpr case=start
// "a good   example"\n
// @lcpr case=end

 */


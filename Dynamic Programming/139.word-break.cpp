/*
 * @lc app=leetcode.cn id=139 lang=cpp
 * @lcpr version=30204
 *
 * [139] 单词拆分
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
    bool s1_wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;

        for(int j = 0; j < wordDict.size(); j++) {
            for(int i = wordDict[j].size(); i <= s.size(); i++) {
                string word = s.substr(i - wordDict[j].size(), wordDict[j].size());

                if(word == wordDict[j] && dp[i - wordDict[j].size()]) {
                    dp[i] = true;
                }
            }
        }
        return dp[s.size()];
    }

    bool s2_wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        vector<bool> dp(s.size() + 1, false);

        dp[0] = true;
        for(int i = 1; i <= s.size(); ++i) {
            for(int j = 0; j < i; ++j) {
                string word = s.substr(j, i - j);
                if(wordSet.find(word) != wordSet.end() && dp[j]) {
                    dp[i] = true;
                }
            }
        }
        return dp[s.size()];
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        return s2_wordBreak(s, wordDict);
    }
};
// @lc code=end



/*
// @lcpr case=start
// "leetcode"\n["leet", "code"]\n
// @lcpr case=end

// @lcpr case=start
// "applepenapple"\n["apple", "pen"]\n
// @lcpr case=end

// @lcpr case=start
// "catsandog"\n["cats", "dog", "sand", "and", "cat"]\n
// @lcpr case=end

 */


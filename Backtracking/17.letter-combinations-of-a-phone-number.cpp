/*
 * @lc app=leetcode.cn id=17 lang=cpp
 * @lcpr version=30204
 *
 * [17] 电话号码的字母组合
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
    std::unordered_map<char, string> map {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };
private:
    vector<string> ans;
    string path;
public:
    void backtracking(int start_num, int start_map, const string& digits) {
        if(path.size() > digits.size()) return;
        
        if(path.size() == digits.size()) {
            if(path.size() != 0)
                ans.push_back(path);
            return;
        }

        for(int i = start_num; i < digits.size(); ++i) {
            for(int j = 0; j < map[digits[i]].size(); j++) {
                path.push_back(map[digits[i]][j]);
                backtracking(i + 1, j, digits);
                path.pop_back();
            }
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        backtracking(0, 0, digits);
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "23"\n
// @lcpr case=end

// @lcpr case=start
// ""\n
// @lcpr case=end

// @lcpr case=start
// "2"\n
// @lcpr case=end

 */


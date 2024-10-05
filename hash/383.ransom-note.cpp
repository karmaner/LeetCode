/*
 * @lc app=leetcode.cn id=383 lang=cpp
 * @lcpr version=30204
 *
 * [383] 赎金信
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
    bool s2_canConstruct(string ransomNote, string magazine) {
        for(auto c:ransomNote){
            int index = magazine.find(c);
            if(index != string::npos)
                magazine[index]=0;
            else
                return false;
        }
        return true;
    }
public:
    bool s1_canConstruct(string ransomNote, string magazine) {
        std::unordered_map<char, int> mapD;
        std::unordered_map<char, int> mapS;
        for(auto c : ransomNote) {
            mapD[c]++;
        }
        for(auto c : magazine) {
            mapS[c]++;
        }
        for(auto c : ransomNote) {
            if(mapS[c] < mapD[c])
                return false;
        }
        return true;
    }
public:
    bool canConstruct(string ransomNote, string magazine) {
        return s2_canConstruct(ransomNote, magazine);
    }
};
// @lc code=end



/*
// @lcpr case=start
// "a"\n"b"\n
// @lcpr case=end

// @lcpr case=start
// "aa"\n"ab"\n
// @lcpr case=end

// @lcpr case=start
// "aa"\n"aab"\n
// @lcpr case=end

 */


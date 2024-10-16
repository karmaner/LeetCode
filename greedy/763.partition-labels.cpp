/*
 * @lc app=leetcode.cn id=763 lang=cpp
 * @lcpr version=30204
 *
 * [763] 划分字母区间
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
    vector<int> partitionLabels(string s) {
        vector<int> ans;
        unordered_set<char> in_there;
        unordered_map<char, int> map;
        for(auto c : s) {
            map[c]++;
        }
        int count = 0;
        for(int i = 0; i < s.size(); ++i) {
            in_there.insert(s[i]);
            map[s[i]]--;
            count++;
            if(map[s[i]] == 0) {
                bool is_ans = true;
                for(auto c : in_there) {
                    if(map[c] != 0) {
                        is_ans = false;
                        break;
                    }
                }
                if(is_ans) {
                    ans.push_back(count);
                    count = 0;
                    in_there.clear();
                }
            }
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "ababcbacadefegdehijhklij"\n
// @lcpr case=end

// @lcpr case=start
// "eccbbbbdec"\n
// @lcpr case=end

 */


/*
 * @lc app=leetcode.cn id=347 lang=cpp
 * @lcpr version=30204
 *
 * [347] 前 K 个高频元素
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
// 小顶堆
class mycomparison {
public:
    bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs) {
        return lhs.second > rhs.second;
    }
};

class Solution {
public:
    vector<int> s1_topKFrequent(vector<int>& nums, int k) { // 本质上是一个排序
        std::unordered_map<int, int> map;
        for(auto i : nums) {
            map[i]++;
        }
        vector<pair<int,int> > temp(map.begin(), map.end());
        sort(temp.begin(), temp.end(), [] (pair<int, int>& a, pair<int, int>& b) {
            return a.second > b.second;
        });

        vector<int> ans;
        for(int i = 0; i < k; ++i) {
            ans.push_back(temp[i].first);
        }
        return ans;
    }

    // 优先队列
    vector<int> s2_topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        for(auto i : nums) {
            map[i]++;
        }

        // 定义一个小顶堆
        std::priority_queue<pair<int, int>, vector<pair<int, int> >, mycomparison> pri_que;

        for(unordered_map<int, int>::iterator it = map.begin(); it != map.end(); it++) {
            pri_que.push(*it);
            if(pri_que.size() > k) {
                pri_que.pop();
            }
        }

        vector<int> ans(k);
        for(int i = k - 1; i >= 0; --i) {
            ans[i] = pri_que.top().first;
            pri_que.pop();
        }
        return ans;

    }
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // return s1_topKFrequent(nums, k);
        return s2_topKFrequent(nums, k);
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,1,1,2,2,3]\n2\n
// @lcpr case=end

// @lcpr case=start
// [1]\n1\n
// @lcpr case=end

 */


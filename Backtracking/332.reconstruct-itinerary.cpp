// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=332 lang=cpp
 * @lcpr version=30113
 *
 * [332] 重新安排行程
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
    // 一半结果超时
    // // 输出结果
    // vector<vector<string>> ans;

    // // 记录一个结果
    // vector<string> path;

    // // 回溯结果
    // void backtracking (vector<vector<string>>& tickets, vector<bool>& used, int use_count) {
    //     if(use_count == tickets.size()) {
    //         ans.push_back(path);
    //         return;
    //     }

    //     for(int i = 0; i < tickets.size(); ++i) {
    //         if(used[i]) continue;
    //         if(path.empty()) {
    //             if(tickets[i][0] == "JFK") {
    //                 path.push_back(tickets[i][0]);  // const JFK
    //                 path.push_back(tickets[i][1]);
    //                 used[i] = true;
    //                 use_count++;
    //             }
    //         } else {
    //             if(tickets[i][0] == path.back()) {
    //                 path.push_back(tickets[i][1]);
    //                 used[i] = true;
    //                 use_count++;
    //             }
    //         }
    //         if(used[i]) {
    //             backtracking(tickets, used, use_count);
    //             use_count--;
    //             used[i] = false;
    //             path.pop_back();
    //         }
    //     }
    // }

    // 一半超时
    // sort(tickets.begin(), tickets.end());
    // vector<bool> used(tickets.size(), false);
    // backtracking(tickets, used, 0);、
    // return ans[0];
// 还得是 用深度优先搜索
private:
    unordered_map<string, map<string, int>> graph;
    vector<string> route;
    
    void dfs(string airport) {
        while (!graph[airport].empty()) {
            string next = graph[airport].begin()->first;
            if (--graph[airport][next] == 0) {
                graph[airport].erase(graph[airport].begin());
            }
            dfs(next);
        }
        route.push_back(airport);
    }

public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        // Build the graph
        for (const auto& ticket : tickets) {
            graph[ticket[0]][ticket[1]]++;
        }

        // Start DFS from JFK
        dfs("JFK");

        // Reverse the route to get the correct order
        reverse(route.begin(), route.end());

        return route;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [["MUC","LHR"],["JFK","MUC"],["SFO","SJC"],["LHR","SFO"]]\n
// @lcpr case=end

// @lcpr case=start
// [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]\n
// @lcpr case=end

 */


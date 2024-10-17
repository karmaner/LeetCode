/*
 * @lc app=leetcode.cn id=63 lang=cpp
 * @lcpr version=30114
 *
 * [63] 不同路径 II
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
	int s1_uniquePathsWithObstacles(vector<vector<int> >& obstacleGrid) {
		int m = obstacleGrid.size();
		int n = obstacleGrid[0].size();
		vector<vector<int> > dp(m, vector<int> (n, 0));

		for(int i = 0; i < m; ++i) {
			if(obstacleGrid[i][0]) {
				break;
			}
			dp[i][0] = 1; 
			cout << dp[i][0] << " ";
		}

		for(int i = 0; i < n; ++i) {
			if(obstacleGrid[0][i]) {
				break;
			}
			dp[0][i] = 1;
			cout << dp[0][i] << " ";
		}

		for(int i = 1; i < m; ++i) {
			for(int j = 1; j < n; ++j) {
				if(obstacleGrid[i][j] == 1) dp[i][j] = 0;
				else dp[i][j] = dp[i - 1][j] + dp[i][j - 1];

				cout << dp[i][j] << " i " << i << " j " << j << endl;
			}
		}
		return dp[m - 1][n - 1];

	}
public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		return s1_uniquePathsWithObstacles(obstacleGrid);
	}
};
// @lc code=end

/*
// @lcpr case=start
// [[0,0,0],[0,1,0],[0,0,0]]\n
// @lcpr case=end

// @lcpr case=start
// [[0,1],[0,0]]\n
// @lcpr case=end

 */

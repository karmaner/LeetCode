/*
 * @lc app=leetcode.cn id=59 lang=cpp
 * @lcpr version=30110
 *
 * [59] 螺旋矩阵 II
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
	// 模拟题
    vector<vector<int>> generateMatrix(int n) {
        int cnt = n / 2;    // 循环次数

        vector<vector<int>> value(n, vector<int> (n,0));
        int i = 0, j = 0;
        int startx = 0, starty = 0; // 偏移量  用于移动方向
        int offset = 1; // 偏移量 保证边界元素
        int count = 1;  // 填入数据

        while (cnt--) {
            for	(i = startx; i < n - offset - startx; i++) {  // 填入第一行
                value[startx][i] = count++;
            }

            for (j = starty; j < n - offset - starty; j++) { // 填入第一列
                value[j][i] = count++;
            }

            for (;i>startx;i--) {
                value[j][i] = count++;
            }

            for (;j>starty;j--) {
                value[j][i] = count++;
            }
            /* 移动到边为n-1的正方形矩阵 */
            startx++;
            starty++;
        }

        if (n % 2 == 1) {
            value[startx][starty] = n * n;
        }
        return value;
    }
    
};
// @lc code=end
int main() {
    Solution solution;
    int n = 0;
    vector<vector<int>> value(n, vector<int> (n)) = solution.generateMatrix(n);
    return 0;
}

/*
// @lcpr case=start
// 3\n
// @lcpr case=end

// @lcpr case=start
// 1\n
// @lcpr case=end

 */


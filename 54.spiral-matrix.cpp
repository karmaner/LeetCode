/*
 * @lc app=leetcode.cn id=54 lang=cpp
 * @lcpr version=30110
 *
 * [54] 螺旋矩阵
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
class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        if (matrix.empty())
            return {};
        int l = 0, r = matrix[0].size() - 1, t = 0, b = matrix.size() - 1;
        vector<int> res;
        while (true)
        {
            for (int i = l; i <= r; i++)
                res.push_back(matrix[t][i]); // left to right
            if (++t > b)
                break;
            for (int i = t; i <= b; i++)
                res.push_back(matrix[i][r]); // top to bottom
            if (l > --r)
                break;
            for (int i = r; i >= l; i--)
                res.push_back(matrix[b][i]); // right to left
            if (t > --b)
                break;
            for (int i = b; i >= t; i--)
                res.push_back(matrix[i][l]); // bottom to top
            if (++l > r)
                break;
        }
        return res;
    }
};
// @lc code=end

int main()
{
    Solution solution;
    vector<vector<int>> res = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    solution.spiralOrder(res);
    return 0;
}

/*
// @lcpr case=start
// [[1,2,3],[4,5,6],[7,8,9]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,2,3,4],[5,6,7,8],[9,10,11,12]]\n
// @lcpr case=end

 */

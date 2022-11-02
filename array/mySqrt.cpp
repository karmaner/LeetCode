/*
        LeetCode : 69
        这同样也是一题二分查找的题目
        left = 0
        right = x

        条件为 m 和 x / m比较 其实就是x 和 m * m 比较
*/

#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

//左闭右闭二分法
class Solution
{
public:
    int mySqrt(int x)
    {
        if (x == 1)
        {
            return 1;
        }
        int min = 0;
        int max = x - 1;
        while (min <= max - 1)
        {
            int middle = max - (max - min) / 2;
            if (x / middle < middle)
            {
                max = middle - 1;
            }
            else
            {
                min = middle;
            }
        }
        return min;
    }
};

int main()
{

    Solution solution;
    int x = 9;
    cout << solution.mySqrt(x) << endl;
    system("pause");
    return 0;
}

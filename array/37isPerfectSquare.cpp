/*
        LeetCode :369题是不是完美的平方数
*/

#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

class Solution
{
public:
    bool isPerfectSquare(int num)
    {
        int min = num >> 2;
        int max = num;
        while (min <= max)
        {
            int middle = min + ((max - min) >> 2);
            if (middle > num / middle)
            {
                max = middle - 1;
            }
            else if (middle < num / middle)
            {
                min = middle + 1;
            }
            else
            {
                return true;
            }
        }
        return false;
    }
};

int main()
{

    Solution solution;
    int num = 5;
    cout << solution.isPerfectSquare(num) << endl;
    system("pause");
    return 0;
}

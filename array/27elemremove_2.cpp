/*
    LeetCode 27 双指针(快慢指针)
    快指针确定值的位置
    慢指针保持位值数据前移
    2022/11/13
*/

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        int slowIndex = 0;
        for (int fastIndex = 0; fastIndex < nums.size(); fastIndex++)
        {
            if (nums[fastIndex] != val)
                nums[slowIndex++] = nums[fastIndex]; // 双指针实现元素交换
        }
        return slowIndex;
    }
};

int main()
{
    Solution solution;
    return 0;
}

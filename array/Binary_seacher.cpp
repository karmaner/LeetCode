/*
    704. 二分查找
        2022/10/30
*/

//注意不同的判断顺序会 可能超时

#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int search(vector<int> &nums, int target)
    {

        int left = 0;
        int right = nums.size() - 1;

        // 特殊情况输出
        if (target < nums[left] || target > nums[right])
            return -1;

        // 一般情况
        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (nums[mid] == target)
            {
                return mid;
            }
            else if (nums[mid] > target)
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        // 没找到
        return -1;
    }
};

int main()
{

    // 数据
    std::vector<int> nums(6);
    int num[] = {-1, 0, 3, 5, 9, 12};
    for (int i = 0; i <= sizeof(num) / sizeof(num[0]) - 1; i++)
        nums[i] = num[i];
    int target = 2;
    Solution *solution = new Solution();
    std::cout << solution->search(nums, target);
    return 0;
}

/*
    双指针或者二分查找
        1. 二分查找 查到一个然后一个向左右两边扩 找到边界

        2. 双指针查找两次遍历
*/

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right)
        {
            int mid = left + ((right - left) >> 1);
            if (target > nums[mid])
            {
                left = mid + 1;
            }
            else if (target < nums[mid])
            {
                right = mid - 1;
            }
            else
            {
                int i = mid; //左找
                int j = mid; //右找
                while (nums[--i] == target && i >= 0)
                {
                    continue;
                };
                i += 1;
                while (nums[++j] == target && j <= nums.size() - 1)
                {
                    continue;
                };
                j -= 1;
                return vector<int>{i, j};
            }
        }
        return vector<int>{-1, -1};
    }
};

int main()
{

    Solution solution;

    vector<int> nums = {1};
    int target = 1;

    //[5,7,7,8,8,10]
    // 6
    vector<int> ans = solution.searchRange(nums, target);

    cout << ans[0] << "\n"
         << ans[1] << endl;

    return 0;
}

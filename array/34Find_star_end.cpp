
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

class Solution1
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

class Solution2
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int leftBorder = -2;
        int rightBorder = -2;
        leftBorder = searchLeftBorder(nums, target);
        rightBorder = searchRightBorder(nums, target);
        // 情况一
        if (leftBorder == -2 || rightBorder == -2)
            return {-1, -1};
        // 情况三
        if (rightBorder - leftBorder > 1)
            return {leftBorder + 1, rightBorder - 1};
        // 情况二
        return {-1, -1};
    }

private:
    int searchRightBorder(vector<int> &nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;
        int rightBorder = -2;
        while (left <= right)
        {
            int mid = left + ((right - left) >> 1);
            if (nums[mid] > target)
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
                rightBorder = left;
            }
            return rightBorder;
        }
        return rightBorder;
    }
    int searchLeftBorder(vector<int> &nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;
        int leftBorder = -2;
        while (left <= right)
        {
            int mid = left + ((right - left) >> 1);
            if (nums[mid] >= target)
            {
                right = mid - 1;
                leftBorder = right;
            }
            else
            {
                left = mid + 1;
            }
            return leftBorder;
        }
        return leftBorder;
    }
};

int main()
{

    Solution1 solution1;

    vector<int> nums = {1};
    int target = 1;

    //[5,7,7,8,8,10]
    // 6
    vector<int> ans = solution1.searchRange(nums, target);

    cout << ans[0] << "\n"
         << ans[1] << endl;

    return 0;
}

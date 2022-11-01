/*
    LeetCode 35
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;
        if (nums[left] > target)
            return left;
        if (nums[right] < target)
            return right;

        while (left <= right)
        {
            int mid = left + ((right - left) >> 2); //>>的操作等级低于+
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] > target)
                right = mid - 1;
            else
                left = mid + 1;
        }
        return left;
    }
};

int main()
{

    return 0;
}
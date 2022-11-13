/*
    2022/11/13
        LeetCode 27元素移除
    思路找到元素 然后元素前移
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
        for (int i = 0; i < nums.size(); i++)
        {
            if (val == nums[i])
            {
                int j = i;
                while (j < nums.size() - 1)
                {
                    nums[j] = nums[j + 1]; // 元素前移
                    j++;
                }
                nums.pop_back();
                i--;
            }
        }
        return nums.size();
    }
};

int main()
{

    Solution solution;
    vector<int> nums = {0, 1, 2, 2, 3, 0, 4, 2};
    int len = solution.removeElement(nums, 2);
    cout << len;
    return 0;
}

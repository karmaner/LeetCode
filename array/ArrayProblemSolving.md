### 		数组题解

---



> 给定一个 n 个元素有序的（升序）整型数组 nums 和一个目标值 target  ，写一个函数搜索 nums 中的 target，如果目标值存在返回下标，否则返回 -1。

> 来源：力扣（LeetCode）
> 链接：https://leetcode.cn/problems/binary-search
> 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。



我的题解 ：

```c++
/*
    LeetCode ：704. 二分查找
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
```

---

* 题解分析

对于特殊情况有处理，至少是不用对于边界外的*target*进行多次判断可以直接输出。

* 二分搜索的两种写法
  1. 闭区间搜索[left,right] <=> 结束条件 left = right
  2. 开区间搜索[left,right) <=> 结束条件 left > right(因为left = right没有意义)



~~越是程序员 越注重攀比~~

程序改进

1. `int mid = left + (right - left) / 2`  防止溢出
2. `int mid = left + (left - right) >> 2 ` 速度更快



---



> 给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。
>
> 请必须使用时间复杂度为 O(log n) 的算法。

> 来源：力扣（LeetCode）
> 链接：https://leetcode.cn/problems/search-insert-position
> 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。



题解：

```c++
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

```


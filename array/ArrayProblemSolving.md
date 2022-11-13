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

LeetCode : 35和二分查找基本相同

---



### LeetCode : 34

>给你一个按照非递减顺序排列的整数数组 nums，和一个目标值 target。请你找出给定目标值在数组中的开始位置和结束位置。
>
>如果数组中不存在目标值 target，返回 [-1, -1]。
>
>你必须设计并实现时间复杂度为 O(log n) 的算法解决此问题
>
>来源：力扣（LeetCode）
>链接：https://leetcode.cn/problems/find-first-and-last-position-of-element-in-sorted-array
>著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。



我的思路

	1. 用二分查找查到该元素，然后在向左向右查找到边界
 	2. 用双指针从左边开始查一个，从右边开始查一个 返回[i , j]

//可能有错误 本地调试可以得出答案，LeetCode上传报错



法一 ：

- [ ] 需要修改查错

```c++

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

```



法二 ：

```c++
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto left=find(nums.cbegin(),nums.cend(),target);//寻找左边第一个出现的数    
        int i=-1,j=-1;//初始化下标为-1
        if(left!=nums.cend()){//左边找到
            i=left-nums.cbegin();//迭代器差值求下标
            j=nums.crend()-1-find(nums.crbegin(),nums.crend(),target);//寻找右边第一个出现的数，迭代器差值求下标
        }
        return {i,j};
    }
};

```

---

+ LeetCode 69 算术平方根

>给你一个非负整数 x ，计算并返回 x 的 算术平方根 。
>
>由于返回类型是整数，结果只保留 整数部分 ，小数部分将被 舍去 。
>
>注意：不允许使用任何内置指数函数和算符，例如 pow(x, 0.5) 或者 x ** 0.5 。
>
>来源：力扣（LeetCode）
>链接：https://leetcode.cn/problems/sqrtx
>著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。



```c++
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

```

向右边界去找分界数



---

2022/11/13 

LeetCode : 27元素移除

```c++
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
                i--; // 防止索引下移 索引回溯
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

```

>算法分析：
>
>时间复杂度：实际上这是一种两次遍历O(n^2) 
>
>空间复杂： O(1)

法二：

>双指针(快慢指针)

```c++
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
```

时间复杂度位O(n)

空间复杂度位O(1)

---

LeetCode 26

```c++
/*
    LeetCode 26
    给你一个 升序排列 的数组 nums ，请你 原地 删除重复出现的元素，使每个元素 只出现一次 ，返回删除后数组的新长度。元素的 相对顺序 应该保持 一致 。

    由于在某些语言中不能改变数组的长度，所以必须将结果放在数组nums的第一部分。更规范地说，如果在删除重复项之后有 k 个元素，那么 nums 的前 k 个元素应该保存最终结果。

    将最终结果插入 nums 的前 k 个位置后返回 k 。

    不要使用额外的空间，你必须在 原地 修改输入数组 并在使用 O(1) 额外空间的条件下完成。

    判题标准:

    来源：力扣（LeetCode）
    链接：https://leetcode.cn/problems/remove-duplicates-from-sorted-array
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


    思路：

    2022/11/13
*/

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int fastIndex = 0; // 用来找重复数据
        int slowIndex = 0; // 记录存储位置
        for (fastIndex = 0; fastIndex < nums.size() - 1; fastIndex++)
        {
            if (nums[fastIndex] != nums[fastIndex + 1])
            {
                nums[slowIndex] = nums[fastIndex]; // 开存
                slowIndex++;                       // 索引后移
            }
        }
        nums[slowIndex] = nums[fastIndex + 1]; // 尾部数据的处理
        return slowIndex + 1;                  // 尾部数据的处理
    }
};

int main()
{
    Solution solution;
    vector<int> nums = {1, 1, 2};
    int len = solution.removeDuplicates(nums);
    cout << len << endl;
    return 0;
}
```




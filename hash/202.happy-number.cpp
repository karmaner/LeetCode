// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=202 lang=cpp
 * @lcpr version=30204
 *
 * [202] 快乐数
 */


// @lcpr-template-start
using namespace std;
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
// @lcpr-template-end
// @lc code=start
class Solution {
std::unordered_map<int, bool> map;  // 放在类外面就解开了
public:
    bool s1_isHappy(int n) { // 递归调用 查重(重复false 不重复满足条件)
        if(n == 1) return true;
        if(map[n]) return false;
        map[n] = true;
        int new_num = 0;
        while(n) {
            int last_digit = n % 10;
            new_num += last_digit * last_digit;
            n /= 10;
        }
        return s1_isHappy(new_num);
    }

    bool s2_isHappy(int n) // 递归
    {
        if (n > 1 && n < 10 && n != 7)
            return false;
        string s = to_string(n);

        int new_n = 0;
        for (auto ch : s)
        {
            int a = ch - '0';
            new_n += a * a;
        }
        if (new_n == 1)
            return true;
        else
            return isHappy(new_n);
    }
private:
    int getSum(int n) {
        int new_num = 0;
        while(n) {
            int last_digit = n % 10;
            new_num += last_digit * last_digit;
            n /= 10;
        }
        return new_num;
    }

    bool s3_isHappy(int n) {    // 快慢指针
        int fast = n;
        int slow = n;

        while(true) {
            slow = getSum(slow);
            fast = getSum(fast);
            fast = getSum(fast);

            if(fast == 1) return true;
            if(fast == slow) return false;
        }
    }
public:
    bool isHappy(int n) {
        return s3_isHappy(n);
    }
};
// @lc code=end



/*
// @lcpr case=start
// 19\n
// @lcpr case=end

// @lcpr case=start
// 2\n
// @lcpr case=end

 */


/*
 * @lc app=leetcode.cn id=344 lang=cpp
 * @lcpr version=30204
 *
 * [344] 反转字符串
 */

// @lc code=start
class Solution {
public:
    void s1_reverseString(vector<char>& s) {
        return reverse(s.begin(), s.end());
    }

    template<typename T>
    void swap(T& a, T& b) {
        T temp = a;
        a = b;
        b = temp;
    }

    template<typename T>
    void swap_bit(T& a, T& b) {
        a ^= b;
        b ^= a;
        a ^= b;
    }

    void s2_reverseString(vector<char>& s) {
        int left = 0, right = s.size() - 1;
        while(left <= right) {
            // std::swap(s[left], s[right]);
            swap(s[left], s[right]);
            left++;
            right--;
        }
    }
public:
    void reverseString(vector<char>& s) {
        // return s1_reverseString(s);
        return s2_reverseString(s);
    }
};
// @lc code=end



/*
// @lcpr case=start
// ["h","e","l","l","o"]\n
// @lcpr case=end

// @lcpr case=start
// ["H","a","n","n","a","h"]\n
// @lcpr case=end

 */


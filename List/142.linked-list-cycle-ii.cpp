/*
 * @lc app=leetcode.cn id=142 lang=cpp
 * @lcpr version=30204
 *
 * [142] 环形链表 II
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
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* s1_detectCycle(ListNode *head) { // map
        ListNode* cur = head;
        std::map<ListNode*, int> map;
        while(cur) {
            map[cur]++;
            if(map[cur] > 1) return cur;
            cur = cur->next;
        }
        return nullptr;
    }

    ListNode* s2_detectCycle(ListNode *head) { // 步频追赶
        /**
         * 相遇时
         *  x 非环走过的距离  y公共起点到相遇点的距离  z相遇点到公共起点的距离
         *  one_step 行走的步伐 x + y
         *  two_step 行走的步伐 x + y + n(y + z)
         *  2(x + y) = x + y + n(y + z)
         *  x = (n - 1) (y + z) + z
         *  x % (一圈长度) = z
         */
        ListNode* one_step = head;
        ListNode* two_step = head;
        while(two_step != nullptr && two_step->next != nullptr) {
            one_step = one_step->next;
            two_step = two_step->next->next;
            if(one_step == two_step) {
                ListNode* index1 = two_step;
                ListNode* index2 = head;
                while(index1 != index2) {
                    index1 = index1->next;
                    index2 = index2->next;
                }
                return index2;
            }
        }
        return nullptr;
    }

    ListNode* s3_detectCycle(ListNode *head) {
        return nullptr;
    }
public:
    ListNode* detectCycle(ListNode *head) {
        // return s1_detectCycle(head);
        return s2_detectCycle(head);
    }
};
// @lc code=end



/*
// @lcpr case=start
// [3,2,0,-4]\n1\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n0\n
// @lcpr case=end

// @lcpr case=start
// [1]\n-1\n
// @lcpr case=end

 */


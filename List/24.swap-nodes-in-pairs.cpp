/*
 * @lc app=leetcode.cn id=24 lang=cpp
 * @lcpr version=30204
 *
 * [24] 两两交换链表中的节点
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
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* s1_swapPairs(ListNode* cur) {    // 循环 伪交换
        ListNode* head = cur;
        while(cur != nullptr && cur->next != nullptr) {
            std::swap(cur->val, cur->next->val);
            cur = cur->next->next;
        }
        return head;
    }

    ListNode* s2_swapPairs(ListNode* head) {
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head; // 虚拟头节点
        ListNode* cur = dummyHead;

        while(cur->next != nullptr && cur->next->next != nullptr) {
            ListNode* tmp1 = cur->next;
            ListNode* tmp2 = cur->next->next->next;

            cur->next = cur->next->next;
            cur->next->next = tmp1;
            cur->next->next->next = tmp2;

            cur = cur->next->next;
        }
        ListNode* result = dummyHead->next;
        delete dummyHead;
        return result;
    }
public:
    ListNode* swapPairs(ListNode* head) {
        // return s1_swapPairs(head);
        return s2_swapPairs(head);
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,4]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

 */


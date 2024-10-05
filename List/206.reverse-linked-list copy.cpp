/*
 * @lc app=leetcode.cn id=206 lang=cpp
 * @lcpr version=30204
 *
 * [206] 反转链表
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
    ListNode* s1_reverseList(ListNode* head) {  // 循环
        // if(head == nullptr || head->next == nullptr) return head;
        // ListNode* pre = nullptr;   // 记录已翻转的链表
        // ListNode* cur = head;
        // ListNode* cur_next = cur->next;
        // while(cur != nullptr && cur_next != nullptr) {
        //     cur->next = pre;
        //     pre = cur;
        //     cur = cur_next;
        //     cur_next = cur_next->next;
        // }
        // cur->next = pre;
        // head = cur;
        // return head;

        // 精简代码
        ListNode* pre = nullptr;   // 记录已翻转的链表
        ListNode* cur = head;
        ListNode* tmp;  // 不参与循环
        while(cur != nullptr) {
            tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }
        head = pre;
        return head;
    }

    ListNode* s2_reverseList(ListNode* head) {  // 递归 一
        if(head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode* last= s2_reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return last;
    }

    // 这个代码 的思想和循环挺像的
    ListNode* s3_reverseList(ListNode* pre, ListNode* cur) {    // 递归 二
        if(cur == nullptr) return pre;
        ListNode* tmp = cur->next;
        cur->next = pre;
        return s3_reverseList(cur, tmp);
    }
public:
    ListNode* reverseList(ListNode* head) {
        // return s1_reverseList(head);
        // return s2_reverseList(head);
        return s3_reverseList(nullptr, head);
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,4,5]\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

 */


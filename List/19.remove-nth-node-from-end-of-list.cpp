/*
 * @lc app=leetcode.cn id=19 lang=cpp
 * @lcpr version=30204
 *
 * [19] 删除链表的倒数第 N 个结点
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
    ListNode* s1_removeNthFromEnd(ListNode* head, int n) {  // stack
        std::stack<ListNode*> stk;
        ListNode* cur = head;
        while(cur) {
            stk.push(cur);
            cur = cur->next;
        }
        while(n--) {
            stk.pop();
        }
        if(stk.empty()) {   // 移除头节点
            ListNode* tmp = head;
            head = head->next;
            delete tmp;
            return head;
        }
        cur = stk.top();
        ListNode* tmp = cur->next;
        cur->next = tmp->next;
        delete tmp;
        return head;
    }

    ListNode* s2_removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;

        ListNode* slow = dummyHead;
        ListNode* fast = dummyHead;
        // FIXED:头节点问题
        while(n-- && fast != nullptr) {    // n
            fast = fast->next;
        }
        fast = fast->next; // + 1
        while(fast != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }
        
        ListNode* tmp = slow->next;
        slow->next = tmp->next;
        delete tmp;
        head = dummyHead->next;
        delete dummyHead;
        return head;
    }
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // return s2_removeNthFromEnd(head, n);
        return s1_removeNthFromEnd(head, n);
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,4,5]\n2\n
// @lcpr case=end

// @lcpr case=start
// [1]\n1\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n1\n
// @lcpr case=end

 */


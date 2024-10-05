/*
 * @lc app=leetcode.cn id=160 lang=cpp
 * @lcpr version=30204
 *
 * [160] 相交链表
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
#include <map>
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
    ListNode* s1_getIntersectionNode(ListNode *headA, ListNode *headB) {    // 使用map
        std::map<ListNode*, int> map;
        while(headA) {
            map[headA]++;
            headA = headA->next;
        }
        while(headB) {
            if(map[headB]) {
                return headB;
            }
            headB = headB->next;
        }
        return nullptr;
    }

    ListNode* s2_getIntersectionNode(ListNode *headA, ListNode *headB) {    // 借助栈 也是借助长度
        std::stack<ListNode*> stk1;
        std::stack<ListNode*> stk2;
        ListNode* cur = headA;
        while(cur) {
            stk1.push(cur);
            cur = cur->next;
        }
        cur = headB;
        while(cur) {
            stk2.push(cur);
            cur = cur->next;
        }
        while(!stk1.empty() && !stk2.empty()) {
            if(stk1.top() != stk2.top()) {  // 长度不等 头部不等
                return stk1.top()->next;
            }
            stk1.pop();
            stk2.pop();
        }
        if(stk1.empty() && !stk2.empty()) return stk2.top()->next; 
        if(stk2.empty() && !stk1.empty()) return stk1.top()->next;
        if(stk1.empty() && stk2.empty()) return headA;
        return nullptr;
    }

    int get_list_len(ListNode* head) {
            ListNode* cur = head;
            int len = 0;
            while(cur) {
                cur = cur->next;
                len++;
            }
        return len;
    }
    ListNode* s3_getIntersectionNode(ListNode *headA, ListNode *headB) {    // 直接用长度
        int lenA = get_list_len(headA), lenB = get_list_len(headB);
        ListNode* curA = headA;
        ListNode* curB = headB;

        int go_first = 0;
        if(lenA > lenB) {
            go_first = lenA - lenB;
            while(go_first--) curA = curA->next;
        }
        if(lenB > lenA) {
            go_first = lenB - lenA;
            while(go_first--) curB = curB->next;
        }
        while(curA != nullptr && curB != nullptr) {
            if(curA == curB) {
                return curA;
            }
            curA = curA->next;
            curB = curB->next;
        }
        return nullptr;
    }
public:
    ListNode* getIntersectionNode(ListNode *headA, ListNode *headB) {
        // return s1_getIntersectionNode(headA, headB);
        // return s2_getIntersectionNode(headA, headB);
        return s3_getIntersectionNode(headA, headB);
    }
};
// @lc code=end



/*
// @lcpr case=start
// 8\n[4,1,8,4,5]\n[5,6,1,8,4,5]\n2\n3\n
// @lcpr case=end

// @lcpr case=start
// 2\n[1,9,1,2,4]\n[3,2,4]\n3\n1\n
// @lcpr case=end

// @lcpr case=start
// 0\n[2,6,4]\n[1,5]\n3\n2\n
// @lcpr case=end

 */


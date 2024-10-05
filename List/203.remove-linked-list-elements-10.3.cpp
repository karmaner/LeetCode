/*
 * @lc app=leetcode.cn id=203 lang=cpp
 * @lcpr version=30204
 *
 * [203] 移除链表元素
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
    // 解法1 原链表操作
    ListNode* s1_removeElements(ListNode* head, int val) {
        while(head != nullptr && head->val == val) {    // 删除头节点数据
            ListNode* tmp = head;
            head = head->next;
            delete tmp;
        }
        ListNode* cur = head;
        while(cur != nullptr && cur->next != nullptr) {
            ListNode* tmp = cur->next;
            if(tmp->val == val) {
                cur->next = tmp->next;
                delete tmp;
            } else {
                cur = cur->next;
            }
        }
        return head;

    }
    // 解法2 递归
    ListNode* s2_removeElements(ListNode* head, int val) {
        if(head == nullptr) {
            return nullptr;
        }

        if(head != nullptr && head->val == val) {
            ListNode* tmp = head;
            head = s2_removeElements(head->next, val);
            delete tmp;
            return head;
        } else {
            head->next = s2_removeElements(head->next, val);
            return head;
        }

    }
    // 解法3 虚拟节点 虚拟没有删除
    ListNode* s3_removeElements(ListNode* head, int val) {
        ListNode* visual_head = new ListNode(0, head);
        ListNode* cur = visual_head;
        while(cur != nullptr && cur->next != nullptr) {
            if(cur->next->val == val) {
                ListNode* tmp = cur->next;
                cur->next = tmp->next;
                delete tmp;
            } else {
                cur = cur->next;
            }
        }
        head = visual_head->next;
        delete visual_head;
        return head;
    }

public:
    ListNode* removeElements(ListNode* head, int val) {
        // return s1_removeElements(head, val);
        // return s2_removeElements(head, val);
        return s3_removeElements(head, val);
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,6,3,4,5,6]\n6\n
// @lcpr case=end

// @lcpr case=start
// []\n1\n
// @lcpr case=end

// @lcpr case=start
// [7,7,7,7]\n7\n
// @lcpr case=end

 */


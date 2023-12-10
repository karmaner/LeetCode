// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=160 lang=cpp
 * @lcpr version=30111
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
class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        // /* 暴力枚举超时 */
        // if (headA == nullptr || headB == nullptr)
        //     return nullptr;

        // ListNode *cur1 = headA, *cur2 = headB;
        // while (cur1)
        // {
        //     while (cur2)
        //     {
        //         if (cur2 == cur1)
        //             return cur1;
        //         cur2 = cur2->next;
        //     }
        //     cur1 = cur1->next;
        // }
        // return nullptr;

        // // 哈希枚举，两次遍历
        // if (headA == nullptr || headB == nullptr)
        //     return nullptr;
        // unordered_map<ListNode *, int> num_A;
        // ListNode *cur = headA;
        // while (cur)
        // {
        //     num_A[cur]++;
        //     cur = cur->next;
        // }
        // cur = headB;
        // while (cur)
        // {
        //     if (num_A[cur] != 0)
        //         return cur;
        //     cur = cur->next;
        // }
        // return nullptr;

        // 双指针   链表对齐一次遍历

        ListNode *curA = headA;
        ListNode *curB = headB;
        int lenA = 0, lenB = 0;
        while (curA != nullptr)
        {
            lenA++;
            curA = curA->next;
        }
        while (curB != nullptr)
        {
            lenB++;
            curB = curB->next;
        }

        /* 对齐操作 */
        curA = headA;
        curB = headB;
        if (lenB > lenA)
        {
            swap(lenA, lenB);
            swap(curA, curB);
        }
        int loop = lenA - lenB;
        while (loop--)
        {
            curA = curA->next;
        }

        /* 查元素 */
        while (curA != nullptr)
        {
            if (curA == curB)
                return curA;
            curA = curA->next;
            curB = curB->next;
        }
        return nullptr;
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

// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=19 lang=cpp
 * @lcpr version=30111
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
class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        /* 快节点向走n步， 快指针走到头时，慢节点走到删除节点 */
        ListNode *dummy = new ListNode(0, head); // 哑节点
        ListNode *fast = dummy;
        ListNode *slow = dummy;
        // 快指针先走n步
        for (int i = 0; i < n + 1; i++)
        {
            fast = fast->next;
        }
        // 快慢指针同时走，直到快指针走到尾部
        while (fast != nullptr)
        {
            fast = fast->next;
            slow = slow->next;
        }
        // 删除倒数第n个节点
        ListNode *temp = slow->next;
        slow->next = slow->next->next;
        delete temp;
        // 返回删除节点后的链表头节点
        ListNode *new_head = dummy->next;
        delete dummy;
        return new_head;
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

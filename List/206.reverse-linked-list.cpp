// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=206 lang=cpp
 * @lcpr version=30111
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
class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        // // 迭代写法
        // ListNode *p = head, *pre = nullptr;

        // while (p)
        // {
        //     ListNode *temp = p->next; // 保存联系
        //     p->next = pre;            // 翻转
        //     // 定位节点
        //     pre = p;
        //     p = temp;
        // }
        // head = pre;
        // return head;

        // 递归写法

        if (head == nullptr || head->next == nullptr) // 无或者单个元素 不需要翻转
            return head;

        ListNode *cur = reverseList(head->next);

        head->next->next = head;

        head->next = nullptr;

        return cur;

        // 递归的二写法
        // ListNode *reverse(ListNode * pre, ListNode * cur)
        // {
        //     if (cur == NULL)
        //         return pre;
        //     ListNode *temp = cur->next;
        //     cur->next = pre;
        //     // 可以和双指针法的代码进行对比，如下递归的写法，其实就是做了这两步
        //     // pre = cur;
        //     // cur = temp;
        //     return reverse(cur, temp);
        // }
        // ListNode *reverseList(ListNode * head)
        // {
        //     // 和双指针法初始化是一样的逻辑
        //     // ListNode* cur = head;
        //     // ListNode* pre = NULL;
        //     return reverse(NULL, head);
        // }
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

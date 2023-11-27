/*
 * @lc app=leetcode.cn id=203 lang=cpp
 * @lcpr version=30110
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

class Solution
{
public:
    ListNode *removeElements(ListNode *head, int val)
    {
        while (head && head->val == val) // 处理头节点
        {
            ListNode *delNode = head;
            head = head->next;
            delete (delNode);
        }

        if (!head)
        {
            return head;
        }

        ListNode *pre = head;
        while (pre->next)
        {
            if (pre->next->val == val)
            {
                ListNode *delNode = pre->next;
                pre->next = pre->next->next;
                delete (delNode);
            }
            else
            {
                pre = pre->next;
            }
        }
        return head;
    }
};
// @lc code=end

int main()
{
    Solution solution;

    solution.return 0;
}
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

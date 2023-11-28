/*
 * @lc app=leetcode.cn id=142 lang=cpp
 * @lcpr version=30111
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
class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        // hash table solution
        unordered_map<ListNode *, int> num_list;

        if (head == nullptr || head->next == nullptr)
            return nullptr;
        ListNode *current = head;
        while (current)
        {
            num_list[current]++;
            if (num_list[current] == 2)
            {
                return current;
            }
            current = current->next;
        }
        return nullptr;

        // // two pointer

        // if (head == nullptr || head->next == nullptr)
        //     return nullptr;
        // ListNode *slow = head, *fast = head;
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

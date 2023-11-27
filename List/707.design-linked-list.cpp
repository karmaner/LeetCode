/*
 * @lc app=leetcode.cn id=707 lang=cpp
 * @lcpr version=30110
 *
 * [707] 设计链表
 */

// @lcpr-template-start
#include <iostream>
using namespace std;
// @lcpr-template-end

// @lc code=start
class MyLinkedList
{
private:
    struct ListNode
    { // 单链表节点结构
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(nullptr) {}
    };
    ListNode *head;

public:
    MyLinkedList()
    {
        head = nullptr;
    }

    int get(int index)
    {
        if (index < 0 || head == nullptr)
        {
            return -1;
        }
        int i = 0;
        ListNode *temp = head;

        while (temp && i < index)
        {
            temp = temp->next;
            i++;
        }
        if (i < index || temp == nullptr)
        {
            return -1;
        }

        return temp->val;
    }

    void addAtHead(int val)
    {
        ListNode *newNode = new ListNode(val);
        newNode->next = head;
        head = newNode;
    }

    void addAtTail(int val)
    {
        ListNode *newNode = new ListNode(val);
        if (head == nullptr)
        {
            head = newNode;
            return;
        }
        ListNode *current = head;
        while (current->next != nullptr)
        {
            current = current->next;
        }
        current->next = newNode;
    }

    void addAtIndex(int index, int val)
    {
        if (index < 0)
        {
            return;
        }
        if (index == 0)
        {
            addAtHead(val);
            return;
        }
        int i = 0;
        ListNode *pre = nullptr;
        ListNode *current = head;
        while (current && i < index)
        {
            pre = current;
            current = current->next;
            i++;
        }
        if (i < index)
        {
            return;
        }
        ListNode *newNode = new ListNode(val);
        newNode->next = current;
        pre->next = newNode;
    }

    void deleteAtIndex(int index)
    {
        if (index < 0 || head == nullptr)
        {
            return;
        }
        if (index == 0)
        {
            ListNode *temp = head;
            head = head->next;
            delete temp;
            return;
        }
        int i = 0;
        ListNode *pre = nullptr;
        ListNode *current = head;
        while (current && i < index)
        {
            pre = current;
            current = current->next;
            i++;
        }
        if (i < index || current == nullptr)
        {
            return;
        }
        pre->next = current->next;
        delete current;
    }
};
// @lc code=end

int main()
{
    // 可以在此处测试您的 MyLinkedList 类的功能
    return 0;
}

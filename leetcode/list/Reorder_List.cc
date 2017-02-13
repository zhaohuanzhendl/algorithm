/*
 * Filename   Reorder_List.cc
 * CreateTime 2017-02-13 13:21:38
 * 
 * Copyright  (C) Zhao Huanzhen
 * Copyright  (C) zhzcsp@gmail.com
 */

#include <iostream>
using namespace std;


struct ListNode {
    int         val;
    ListNode   *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    void reorderList(ListNode *head)
    {
        if (head == nullptr) {
            return head;
        }

        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *prev = nullptr;

        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        prev->next = nullptr; //cut

        slow = reverse(slow);
        ListNode *tmp = nullptr; 
        
        ListNode *cur = head;
        while (cur->next) {
            tmp = cur->next;
            cur->next = slow;
            slow = slow->next;
            cur->next->next = tmp;
            cur = cur->next->next; //equal to tmp
        }
        cur->next = slow;

    }

    ListNode *reverse(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode *prev = head;
        for (ListNode *cur = head->next, *next = cur->next;
                cur;
                prev = cur, cur = next, next = next ? next->next : nullptr) {
            cur->next = prev;
        }
        head->next = nullptr;

        return prev;
    }

    ListNode *reverse_new(ListNode *prev, ListNode *next)
    {
        ListNode *last = prev->next;
        ListNode *cur  = last->next;

        while (cur != next) {
            last->next = cur->next;
            cur->next = prev->next;
            prev->next = cur;
            cur = last->next;
        }

        return  last;
        
    }
};


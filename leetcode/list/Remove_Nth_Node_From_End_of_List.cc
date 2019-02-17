/*
 * Filename   Remove Nth Node From End of List.cc
 * CreateTime 2017-02-08 17:13:41
 * 
 * Copyright  (C) Zhao Huanzhen
 * Copyright  (C) zhzcsp@gmail.com
 */

#include <iostream>
using namespace std;


struct ListNode {
    int         val;
    ListNode   *next;
    ListNode(int x, ListNode *p) : val(x), next(p) {}
};


class Solution {
public:
    ListNode *rm_n(ListNode *head, int n)
    {
        if (head == nullptr || n < 0 ) return head;
        ListNode    dummy(-1);
        ListNode    *p = &dummy; *q = &dummy;
        
        //make sure : n < len
        for (int i = 0; i < n; i++) {
            q = q->next;
        }

        while (q->next) {
            q = q->next;
            p = p->next;
        }

        ListNode *tmp = p->next;
        p->next = p->next->next;

        delete tmp;

        return dummy.next;
        
    }

    ListNode *rm_nth_end(ListNode *head, int n)
    {
        ListNode dummy(-1);
        dummy.next = head;
        ListNode *p = &dummy, *q=&dummy;

        for (int i=0; i<n; i++)
            q = q->next;

        while (q->next) {
            p = p->next;
            q = q->next;
        }

        ListNode *tmp = p->next;
        p->next = p->next->next;
        delete tmp;

        return dummy.next;
    }
};



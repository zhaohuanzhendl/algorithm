/*
 * Filename   swap_nodes.cc
 * CreateTime 2017-02-09 06:31:31
 * 
 * Copyright  (C) Zhao Huanzhen
 * Copyright  (C) zhzcsp@gmail.com
 */

#include <iostream>
using namespace std;


struct ListNode {
    int         val;
    ListNode   *next;
    ListNode(int val) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *swap_node(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode dummy(-1);
        dummy.next = head;

        for (ListNode *prev = &dummy, *cur = prev->next, next = cur->next;
                next;
                prev = cur, cur = cur->next, next = cur ? cur->next : nullptr) {

            prev->next = next;
            cur->next = next->next;
            next->next = cur;
        
        }
        
        return dummy.next;
    }

    ListNode *swap_node_new(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode dummy(-1);
        dummy.next = head;

        for (ListNode *prev = &dummy, *cur = prev->next, *next=cur->next;
             next;
             prev = cur, cur = cur->next, next = cur?cur->next:nullptr) {

            prev->next = next;//cur->next
            cur->next = next->next;
            next->next = cur; //prev->next->next = cur
        
        }

        return dummy.next;
    }
};

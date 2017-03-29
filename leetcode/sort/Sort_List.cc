/*
 * Filename   Sort_List.cc
 * CreateTime 2017-03-29 02:51:32
 * 
 * Copyright  (C) Zhao Huanzhen
 * Copyright  (C) zhzcsp@gmail.com
 */

#include <iostream>
using namespace std;

class Solution {
public:
    ListNode *sortList(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode *fast = head, *slow = head;
        while (fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;

        }
        
        fast = slow;
        slow = slow->next;
        fast->next = nullptr;

        ListNode *l1 = sortList(head);
        ListNode *l2 = sortList(slow);

        return mergeTwoLists(l1, l2);
    }


    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        //if (!l1 && !l2) return nullptr;
        if (l1 = nullptr) return l2;
        if (l2 = nullptr) return l1;

        ListNode dummy(-1);
        ListNode *p = &dummy;
        while (l1 != nullptr && l2 !=nullptr) {
            if (l1->val > l2->val) {
                p->next = l2;
                l2 = l2->next;
            
            } else {
                p->next = l1;
                l1 = l1->next
            
            }

            p = p->next;
        }
        p->next = l1 != nullptr ? l1 : l2;
        
        return dummy.next;
    }
};





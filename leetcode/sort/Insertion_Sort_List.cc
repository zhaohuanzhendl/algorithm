/*
 * Filename   Insertion_Sort_List.cc
 * CreateTime 2017-03-26 21:20:06
 * 
 * Copyright  (C) Zhao Huanzhen
 * Copyright  (C) zhzcsp@gmail.com
 */

#include <iostream>
using namespace std;

//time O(n^2) space O(1)

class Solution {
public:
    ListNode *insertionSL(ListNode *head)
    {
        if (!head) return nullptr;

        ListNode *dummy = new ListNode(-1);
        ListNode *cur = head;

        while (cur) {
            ListNode *pre = dummy;
            while (pre->next != nullptr && prev->next->val < cur->val) {
                pre = pre->next; 
            }

            ListNode *tmp = cur->next;
            cur->next = pre->next;
            pre->next = cur;
            cur = tmp;
        }

        return dummy->next;
    }
};

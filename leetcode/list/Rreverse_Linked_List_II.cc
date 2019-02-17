/*
 * Filename   Rreverse_Linked_List_II.cc
 * CreateTime 2019-02-17 14:28:31
 * 
 * Copyright  (C) Zhao Huanzhen
 * Copyright  (C) zhzcsp@gmail.com
 */

#include <iostream>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *reverse(ListNode *head, int m, int n)
    {
        if (m<1 || m>=n || !head) return head;
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        head = dummy;

        for (int i=0; i<m-1; i++) 
            head = head->next;

        ListNode *pre = head->next, *cur = pre->next;
        for (int i=m; i<n; i++) {
            ListNode *temp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = temp;
        }

        head->next->next = cur;
        head->next = pre;
        head = dummy->next;
        delete dummy;

        return head;
    }
};

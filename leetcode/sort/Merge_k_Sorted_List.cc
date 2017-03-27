/*
 * Filename   Merge_k_Sorted_List.cc
 * CreateTime 2017-03-26 18:59:01
 * 
 * Copyright  (C) Zhao Huanzhen
 * Copyright  (C) zhzcsp@gmail.com
 */

#include <iostream>
using namespace std;

class Solution {
public:
    ListNode *mergeKList(vector<ListNode *> &lists)
    {
        if (lists.size() == 0) return nullptr;
        ListNode *p = lists[0];

        for (int i = 1; i < lists.size(); i++) {
            p = mergeTwoLists(p, lists[i]);
        
        }

        return p;
    }

    ListNode *mergeTwoLists(ListNode *lst, ListNode *lnd)
    {
        if (lst == nullptr) return lnd;
        if (lnd == nullptr) return lst;
        
        ListNode head(-1);
        ListNode *p = &head; 

        for (; lst != nullptr && lnd != nullptr; p = p->next) {
            if (lst->val > lnd->val) {
                p->next = lnd;
                lnd = lnd->next;
            } else {
                p->next = lst;
                lst = lst->next;
            }
        } 

        p->next = lst != nullptr ? lst : lnd;
        return head.next;
    }
};


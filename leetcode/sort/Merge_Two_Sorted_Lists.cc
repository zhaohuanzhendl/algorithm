/*
 * Filename   Merge_Two_Sorted_Lists.cc
 * CreateTime 2017-03-26 18:21:57
 * 
 * Copyright  (C) Zhao Huanzhen
 * Copyright  (C) zhzcsp@gmail.com
 */

#include <iostream>
using namespace std;

class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l_st, ListNode *l_nd)
    {
        if (!l_st) return l_nd;
        if (!l_nd) return l_st;

        ListNode dummy(-1);
        ListNode *p = &dummy;
        for (; l_st != nullptr && l_nd !=nullptr; p = p->next) {
            if (l_st->val > l_nd->val) {
                p->next = l_nd;
                l_nd = l_nd->next;

            } else {
                p->next = l_st;
                l_st = l_st->next;
            
            }
        }

        p->next = l_st != nullptr ? l_st : l_nd;

        return dummy.next;
    }
};

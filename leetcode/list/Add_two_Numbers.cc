/*
 * Filename   Add_two_Numbers.cc
 * CreateTime 2019-02-17 08:44:10
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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode dummy(-1);
        int carry = 0;
        ListNode *prev = &dummy;
        for (ListNode *p1=nullptr, *p2=nullptr; 
            p1!= nullptr || p2 !=nullptr;
            p1 = p1 ==nullptr? nullptr:p1->next,
            p2 = p2 ==nullptr? nullptr:p2->next,
            prev=prev->next) {
            const int v1 = p1 == nullptr? 0: p1->val; 
            const int v2 = p2 == nullptr? 0: p2->val; 
            const value = (v1+v2+carry) % 10;
            carry = (v1+v2+carry) / 10;
            prev->next = listNode(value);
        }
        if (carry>0)
            prev->next = new ListNode(carry);

        return dummy.next;
    }
};

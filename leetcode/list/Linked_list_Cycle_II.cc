/*
 * Filename   Linked_list_Cycle_II.cc
 * CreateTime 2017-02-13 11:27:27
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
    ListNode *detectStartpoint(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;

        while (slow && fast) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow && fast) {
                ListNode *slow2 = head;

                while (slow2 != slow) {
                    slow2 = slow2->next;
                    slow = slow->next;
                }

                return slow2;
            }
        }

        return nullptr;
    }
};


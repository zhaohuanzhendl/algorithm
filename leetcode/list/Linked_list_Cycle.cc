/*
 * Filename   Linked_list_Cycle.cc
 * CreateTime 2017-02-13 09:32:28
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
    bool hasCycle(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;

        while (slow && fast) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                return true;
            }

        }

        return false;
    }
};


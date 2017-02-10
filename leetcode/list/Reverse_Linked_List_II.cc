/*
 * Filename   Reverse_Linked_List_II.cc
 * CreateTime 2017-02-08 11:30:53
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
    ListNode *reversBetween(ListNode *head, int m, int n)
    {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;

        ListNode *prev = dummy, *cur = head;

        for (int i = 1; i < m; i++) {
            prev = cur;
            cur = cur->next;
        }

        ListNode *p1, *p2;

        if (cur) {
            p1 = cur->next;
        }

        if (p1) {
            p2 = p1->next;
        }

        for (int j = m; j < n; j++) {
            p1->next = cur;
            cur = p1;
            p1 = p2;
            if (p2) {
                p2 = p2->next;
            }
        }

        prev->next->next = p1;
        prev->next = cur;

        return dummy->next;

    }
};

/*
 * first:
 *        prev -> cur -> p1 -> p2  
 *          .      .     .     .
 * dummy -> 1  ->  2  -> 3  -> 4 -> 5 -> 6 ->null
 *
 * prev-final:
 *        prev                     cur -> p1 -> p2  
 *          .                       .     .     .
 *          1  ->  2  <- 3  <- 4 <- 5 -x- 6 ->null
 *       
 * finally:
 *               ____________________
 *              |                    |
 *          1   2  <- 3  <- 4 <- 5   6 ->null
 *          |____________________|
 *
 */

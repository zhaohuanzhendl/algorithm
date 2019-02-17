/*
 * Filename   Partition_list.cc
 * CreateTime 2017-02-08 15:17:18
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


/* Trains of Thought:
 * 
 * get two list, and walk the original list.  when case the val less than the
 *  value x, attach the node to p1, othervise the val equal or given the 
 *  value x, attach the node to p2.
 *
 * after the list walk, attach the p2 to the end of p1.
 */

class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        ListNode dummy1(0), dummy2(0);
        ListNode *p1 = &dummy1, *p2 = &dummy2;

        ListNode *p = head;

        while (p) {
            if (p->val < x) {
                p1->next = p;
                p1 = p1->next;
            } else {
                p2->next = p;
                p2 = p2->next;
            }

            p = p->next;
        }

        p1->next = dummy2.next;
        p2->next = nullptr;

        return dummy1.next;
    }

};


//TEST UNIT

int main()
{
    
    ListNode *head = new ListNode(1);
    ListNode *temp = head;
    temp = temp->next = new ListNode(4);
    temp = temp->next = new ListNode(3);
    temp = temp->next = new ListNode(2);
    temp = temp->next = new ListNode(5);
    temp = temp->next = new ListNode(2);

    Solution S;
    ListNode *res = S.partition(head, 3);

    while (res) {
        cout << res->val << " ";
        res = res->next;
    }

    cout << endl << "Finish walk res list!" << endl;

    return 0;

}


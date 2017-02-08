/*
 * Filename   Remove_Duplicates_from_Sorted_List.cc
 * CreateTime 2017-02-08 16:00:12
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
    ListNode *delDup(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode dummy(0);
        dummy.next = head;
        ListNode *p = head;

        while (p && p->next) {
            if (p->val == p->next->val) {
                ListNode *temp = p->next;
                p->next = p->next->next;

                delete temp; 

            } else {
                p = p->next;

            }
        }

        return dummy.next; 
    }

};

//UNITTEST

int main()
{
    ListNode *head = new ListNode(1);
    ListNode *tmp = head;
    tmp = tmp->next = new ListNode(1);
    tmp = tmp->next = new ListNode(2);
    tmp = tmp->next = new ListNode(3);
    tmp = tmp->next = new ListNode(3);

    Solution S;

    ListNode *res = S.delDup(head);

    while (res) {
        cout << res->val << " ";
        res = res->next;
    }

    cout << endl << "Finish~~" << endl;

    return 0;

}

/*
 * Filename   Rotate_list.cc
 * CreateTime 2017-02-08 05:05:13
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
        ListNode *rotate(ListNode *head, int k)
        {
            if (head == nullptr || k == 0) {
                return head;
            }

            int len = 1;
            ListNode *p = head;

            while (p->next) {
                len++;
                p = p->next;
            }

            k = len - k % len;

            p->next = head;
            for (int step = 0; step < k; step++) {
                p = p->next;
            
            }

            head = p->next;
            p->next = nullptr;

            return head;
        
        }
};

//UNITTEST
int main()
{
    ListNode *head = new ListNode(1);
    ListNode *tmp = head;
    for (int i = 2; i < 6; i++ ) {
        tmp = tmp->next = new ListNode(i);
    }

    Solution S;
    ListNode *res = S.rotate(head, 2);

    while (res) {
        cout << res->val << " ";
        res = res->next;
    }

    cout << endl << "DONE!!" << endl;

    return 0;
}

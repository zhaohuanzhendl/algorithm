/*
 * Filename   Revers_Nodes_in_kGroups.cc
 * CreateTime 2017-02-10 10:17:40
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
    
    ListNode *revers_kgroup(ListNode *head, int k)
    {
        if (head == nullptr || k == 1) {
            return head;
        }

        ListNode *dummy = new ListNode(-1);
        ListNode *prev = dummy, *cur = head;
        dummy->next = head;

        int i = 0;
        while (cur) {
            ++i;
            if (i % k == 0) {
                prev = reverseOneGroup(prev, cur->next);
                cur = prev->next;
            } else {
                cur = cur->next;
            }
        }

        return dummy->next;
        
    }

    ListNode *reverseOneGroup(ListNode *prev, ListNode *next)
    {
        ListNode *last = prev->next;
        ListNode *cur = last->next;

        while (cur != next) {
            last->next = cur->next;
            cur->next = prev->next;
            prev->next = cur;
            cur = last->next;
        }

        return last;
    }

};

//UNITTEST
int main()
{
    ListNode *head = new ListNode(1);
    ListNode *tmp = head;
    for (int i = 1; i < 6; i++) {
        tmp->next = new ListNode(i + 1);
        tmp = tmp->next;
    }
    tmp = head;
    cout << "orginal list:" <<endl;
    while (tmp) {
        cout << tmp->val << " ";
        tmp = tmp->next;
    }
    cout << endl;

    Solution S;
    ListNode *res = S.revers_kgroup(head, 2);

    cout << endl << "new list:" <<endl;
    while(res) {
        cout << res->val << " ";
        res = res->next;
    }
    cout << endl << "Done!!" << endl;

    return 0;
}

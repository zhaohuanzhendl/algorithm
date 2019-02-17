/*
 * Filename   Revers_Nodes_in_kGroups.cc
 * CreateTime 2017-02-10 10:17:40
 * 
 * Copyright  (C) Zhao Huanzhen
 * Copyright  (C) zhzcsp@gmail.com
 */

#include <iostream>
using namespace std;

/*
 *ref:http://www.cnblogs.com/grandyang/p/4441324.html
 *
 *这道题让我们以每k个为一组来翻转链表，实际上是把原链表分成若干小段，
 *然后分别对其进行翻转，那么肯定总共需要两个函数，一个是用来分段的，
 *一个是用来翻转的，我们就以题目中给的例子来看，对于给定链表1->2->3->4->5，
 *一般在处理链表问题时，我们大多时候都会在开头再加一个dummy node，
 *因为翻转链表时头结点可能会变化，为了记录当前最新的头结点的位置而引入的dummy node，
 *那么我们加入dummy node后的链表变为-1->1->2->3->4->5，如果k为3的话，
 *我们的目标是将1,2,3翻转一下，那么我们需要一些指针，
 *pre和next分别指向要翻转的链表的前后的位置，然后翻转后pre的位置更新到如下新的位置：
 *
 *-1->1->2->3->4->5
 * |           |
 *pre         next
 *-1->3->2->1->4->5
 *          |  |
 *         pre next
 */

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

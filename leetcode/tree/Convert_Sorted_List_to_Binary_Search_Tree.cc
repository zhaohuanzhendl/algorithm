/*
 * Filename   Convert_Sorted_List_to_Binary_Search_Tree.cc
 * CreateTime 2017-03-20 18:28:07
 * 
 * Copyright  (C) Zhao Huanzhen
 * Copyright  (C) zhzcsp@gmail.com
 */

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
//bottom-up  sapce O(n), time O(logn)

class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head)
    {
        int len = 0;
        TreeNode *p = head;

        while (p) {
            len++;
            p = p->next;
        }

        return sortedListToBST(head, 0, len - 1);
    }

    TreeNode *sortdeListToBST(ListNode *list, int start, int end)
    {
        if (start > end) return nullptr;

        int mid = start + (end - start) / 2;
        TreeNode *leftChild = sortedListToBST(list, start, mid - 1);
        TreeNode *parent = new TreeNode(list->val);
        parent->left = leftChild;
        list = list->next;
        parent->right= sortedListToBST(list, mid + 1, end);
        
        return parent;
    }
};

int main()
{
    
}

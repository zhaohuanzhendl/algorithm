/*
 * Filename   Populating_Next_Right_Pointers_Each_Node.cc
 * CreateTime 2017-03-23 13:06:27
 * 
 * Copyright  (C) Zhao Huanzhen
 * Copyright  (C) zhzcsp@gmail.com
 */

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    void connect(TreeLinkNode *root)
    {
        while (root) {
           TreeLinkNode *next = nullptr; //first node of next level   
           TreeLinkNode *prev = nullptr; //previous node on the same level   

           for (; root; root = root->next) {
              if (!next) next = root->left ? root->left : root->right;

              if (root->left) {
                  if (prev) prev->next = root->left;
                  prev = root->left;
               
              }

              if (root->right) {
                  if (prev) prev->next = root->right;
                  prev = root->right;
               
              }
           
           }

           root = next;
        }
    }
};

class Solution_recu {
public:
    void connect(TreeLinkNode *root)
    {
        if (!root) return;

        TreeLinkNode dummy(-1);
        for (TreeLinkNode *curr = root, *prev = &dummy; curr; curr = cur->next) {
            if (curr->left != nullptr) {
                prev->next = curr->left;
                prev = prev->next;
            }
            if (curr->right != nullptr) {
                prev->next = curr->right;
                prev = prev->next;
            }
        
        } //end for

        connect(dummy.next);
    }
};

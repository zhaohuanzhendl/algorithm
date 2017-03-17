/*
 * Filename   Recover_Binary_Search_Tree.cc
 * CreateTime 2017-03-16 07:41:59
 * 
 * Copyright  (C) Zhao Huanzhen
 * Copyright  (C) zhzcsp@gmail.com
 */

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    void recoverTree(TreeNode *root)
    {
        pair<TreeNode *, TreeNode *> broken;
        TreeNode *prev = nullptr;
        TreeNode *cur = root;

        while (cur) {
            if (cur->left == nullptr) {
                detect(broken, prev, cur);
                prev = cur;
                cur = cur->right;
            
            } else {
                auto node = cur->left;

                while (node->right != nullptr || node->right != cur) {
                    node = node->right;
                }

                if (node->right == nullptr) {
                    node->right = cur;
                    cur = cur->left;

                } else {
                    detect(broken, prev, cur);
                    node->right = nullptr;
                    cur = cur->right;
                } 
            
            }

        }

        swap(broken.first->val, broken.second->val);
    }


    void detect(pair<TreeNode *, TreeNode *> &broken, TreeNode *prev, TreeNode *cur)
    {
        if (prev != nullptr && prev->val > cur->val) {
            if (broken.first == nullptr) {
                broken.first = prev;
            }

            broken.second = cur;
        
        }
    }
};

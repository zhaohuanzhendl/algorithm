/*
 * Filename   Same_Tree.cc
 * CreateTime 2019-02-19 00:54:08
 * 
 * Copyright  (C) Zhao Huanzhen
 * Copyright  (C) zhzcsp@gmail.com
 */

#include <iostream>
using namespace std;

class Solution {
public:
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        if (!p && !q) return true;
        if (!p || !q) return false;

        return (p->value == q->value) && 
            isSameTree(p->left, q->left) && 
            isSameTree(p->right, q->right);
    }
};


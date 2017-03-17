/*
 * Filename   Same_Tree.cc
 * CreateTime 2017-03-16 19:29:10
 * 
 * Copyright  (C) Zhao Huanzhen
 * Copyright  (C) zhzcsp@gmail.com
 */

#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

class Solution_recu {
public:
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        if (!p && !q) return true;
        if (!p || !q) return false;

        return p->val == q->val 
            && isSameTree(p->left, q->left) 
            && isSameTree(p->right, q->right);
    }
};



class Solution_stack {
public:
    bool isSameTree(TreeNode *T1, TreeNode *T2)
    {
        TreeNode *p = T1, *q = T2;
        stack<TreeNode *> s;

        if (!p && !q)  return true;
        if (!p || !q)  return false;

        while (!s.empty()) {
            p = s.top();
            s.pop();
            q = s.top();
            s.pop();

            if (!p && !q)  return true;
            if (!p || !q)  return false;

            if (p->val != q->val) return false; 

            s.push(p->left);
            s.push(q->left);
        
            s.push(p->right);
            s.push(q->right);

        }
        
        return true;
    }
};

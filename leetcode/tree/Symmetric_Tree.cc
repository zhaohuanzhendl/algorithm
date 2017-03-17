/*
 * Filename   Symmetric_Tree.cc
 * CreateTime 2017-03-16 20:04:21
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
    bool isSymmtric(TreeNode *root)
    {
        return root ? isSymmtric(root->left, root->right) : true;
    }

    bool isSymmtric(TreeNode *left, TreeNode *right)
    {
        if (!left && !right) return true;
        if (!left || !right) return false; 

        return left->val == right->val
            && isSymmtric(left->left, right->right) 
            && isSymmtric(left->right, right->left);
    }
};


class Solution_recu {
public:
    bool isSymmtric(TreeNode *root)
    {
        if (!root) return true;

        TreeNode *p = root;
        stack<TreeNode *> s;
        s.push(p->left);
        s.push(p->right);

        while (!s.empty()) {
            auto p = s.top();
            s.pop();
            auto q = s.top();
            s.pop();
            
            if (!p && !q)  continue;
            if (!p || !q) return false;
            if (p->val != q->val) return false;

            s.push(p->left);
            s.push(q->right);
            
            s.push(p->right);
            s.push(q->left);
        }

        return true;
    }
};

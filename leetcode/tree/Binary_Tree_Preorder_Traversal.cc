/*
 * Filename   Binary_Tree_Preorder_Traversal.cc
 * CreateTime 2017-03-14 17:27:53
 * 
 * Copyright  (C) Zhao Huanzhen
 * Copyright  (C) zhzcsp@gmail.com
 */

#include <iostream>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr); 
};

//stack 
class Solution_s {
public:
    vector<int> preorderT(TreeNode *root)
    {
        vector<int> result;
        const TreeNode *p;
        stack<const TreeNode *> s;

        p = root;
        if (p != nullptr) s.push(p); 

        while(!s.empty) {
           p = s.top(); 
           s.pop();
           result.push_back(p->value);

           if (p->right != nullptr) s.push(p->right);
           if (p->left != nullptr) s.push(p->left);
        }
    }
};


//morris
class Solution_m {
public:
    vector<int> preorderT(TreeNode *root)
    {
        vector<int> result;
        TreeNode *cur, *prev;

        cur = root;
        while (cur != nullptr) {
            if (cur->left == nullptr) {
                result.push_back(cur->val);
                prev = cur;
                cur = cur->left;
            
            } else {
                /*search the prev point*/
                TreeNode *node = cur->left;
                while (node->right != nullptr && node->right != cur) {
                    node = node->right;
                }
                
                if (node->right == nullptr) {
                    result.push_back(cur->val);
                    node->right = cur;
                    prev = cur;
                    cur = cur->left;
                
                } else {
                    node->right = nullptr;
                    cur = cur->right;
                
                }

            }
        
        }

        return result;
    }
};


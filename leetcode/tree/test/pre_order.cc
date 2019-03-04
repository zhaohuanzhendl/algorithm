/*
 * Filename   pre_order.cc
 * CreateTime 2019-02-18 22:15:13
 * 
 * Copyright  (C) Zhao Huanzhen
 * Copyright  (C) zhzcsp@gmail.com
 */

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {} 
};


class Solution {
public:
    vector<int> pre_t(TreeNode *root)
    {
        vector<int> result;
        stack<const TreeNode *> s;
        const TreeNode *p;

        p = root;
        if (p != nullptr) s.push(p);
        
        while (!s.empty()) {
            p = s.top();
            s.pop();
            result.push_back(p->val);

            if (p->right != nullptr) s.push(p->right);
            if (p->left != nullptr) s.push(p->left);
        }

        return result;
    }

    vector<int> in_t(TreeNode *root)
    {
        vector<int> result;
        const TreeNode *p;
        stac<const TreeNode *> s;

        p = root;
        while (!s.empty() || p != nullptr) {
            if (p != nullptr) {
                s.push(p);
                p = p->left;
            } else {
                p = s.top();
                s.pop();
                result.push_back(p->val);
                p = p->right;
            }
        }
    }
};

/*
 * Filename   print_tree_by_level.cc
 * CreateTime 2019-03-05 00:07:33
 * 
 * Copyright  (C) Zhao Huanzhen
 * Copyright  (C) zhzcsp@gmail.com
 */

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> levelOreder(TreeNode *root)
    {
        vector<int> ret;
        queue<TreeNode *> q;

        if (root == nullptr) {
            return ret;
        }

        q.push(root);
        while (!q.empty()) {
            TreeNode *temp = q.front();
            q.pop();
            ret.push_back(temp->val);
            
            if (temp->left) q.push(temp->left);
            if (temp->right) q.push(temp->right);

        }

        return ret;
    }

}



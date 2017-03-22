/*
 * Filename   Ptah_Sum.cc
 * CreateTime 2017-03-21 20:51:11
 * 
 * Copyright  (C) Zhao Huanzhen
 * Copyright  (C) zhzcsp@gmail.com
 */

#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool hasPathSum(TreeNode *root, int sum)
    {
        if (!root) return false;
        
        if (root->left == nullptr && root->right == nullptr)
            return sum == root->val;

        return hasPathSum(root->left, sum - root->val)
                || hasPathSum(root->right, sum - root->val);
    }
};



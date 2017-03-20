/*
 * Filename   Balanced_Tree.cc
 * CreateTime 2017-03-17 05:37:58
 * 
 * Copyright  (C) Zhao Huanzhen
 * Copyright  (C) zhzcsp@gmail.com
 */

#include <iostream>
using namespace std;

class Solution {
public:
    bool isBalanced(TreeNode *root)
    {
        //if (!root) return true;
        return balancedHeight(root) >= 0;
    }

    int balancedHeight(TreeNode *root)
    {
        if (!root)  return 0;

        int left = balancedHeight(root->left);
        int right= balancedHeight(root->right);

        if (left < 0 || right < 0 || abs(left - right) > 1) return -1;

        return max(left, right) + 1;
    }
};

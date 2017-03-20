/*
 * Filename   Validate_Binary_Search_Tree.cc
 * CreateTime 2017-03-19 22:30:19
 * 
 * Copyright  (C) Zhao Huanzhen
 * Copyright  (C) zhzcsp@gmail.com
 */

#include <iostream>
using namespace std;

class Solution_Inorder {
public:
    bool isValidBST(TreeNode *root)
    {
        int curMax = INT_MIN;
        return validateBST(root, curMax);
    }

    bool validateBST(TreeNode *root, int &curMax)
    {
        if (!root) return true;
        if (!validateBST(root->left, curMax)) return false;
        if (curMax >= root->val) return false;
        curMax = root->val;
        return validateBST(root->right, curMax);
    }
};



class Solution_B {
public:
    bool isValidBST(TreeNode *root)
    {
        return isValidBST(TreeNode *root, INT_MIN, INT_MAX);
    }

    bool isValidBST(TreeNode *root, int lower, int upper)
    {
        if (!root)  return true;

        return root->val > lower && root->val < upper
            && isValidBST(root->left, lower, root->val)
            && isValidBST(root->right, root->val, upper);
    }
};

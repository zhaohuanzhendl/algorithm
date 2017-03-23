/*
 * Filename   Sum_Root_to_Leaf_Numbers.cc
 * CreateTime 2017-03-23 20:01:10
 * 
 * Copyright  (C) Zhao Huanzhen
 * Copyright  (C) zhzcsp@gmail.com
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
publics:
    int sumNum(TreeNode *root)
    {
        return dfs(root, 0);
    }

private:

    int dfs(TreeNode *root, int sum)
    {
        if (!root) return 0;

        if (root->left == nullptr && root->right == nullptr) {
            return sum * 10 + root->val;
        }

        return dfs(root->left, sum * 10 + root->val) 
                + dfs(root->right, sum * 10 + root->val);
    }

};

/*
 * Filename   Minmum_Depth_of_Binary_Tree.cc
 * CreateTime 2017-03-21 05:26:23
 * 
 * Copyright  (C) Zhao Huanzhen
 * Copyright  (C) zhzcsp@gmail.com
 */

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int minDepth(const TreeNode *root)
    {
        return minDepth(root, false);

    }

private:
    int minDepth(const TreeNode *root, bool root_brother)
    {
        if (!root) return root_brothre ? INT_MAX : 0;

        return 1 + min (minDepth(root->left, root->right != nullptr),
                minDepth(root->right, root0->left != nullptr));
    }
};

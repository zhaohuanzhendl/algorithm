/*
 * Filename   Maximum_Depth_of_Binary.cc
 * CreateTime 2017-03-21 08:48:25
 * 
 * Copyright  (C) Zhao Huanzhen
 * Copyright  (C) zhzcsp@gmail.com
 */

#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxDepth(TreeNode *root)
    {
        if (root == nullptr) return 0;

        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};

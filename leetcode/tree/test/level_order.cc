/*
 * Filename   level_order.cc
 * CreateTime 2019-02-19 00:40:07
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
    vector<vector<int> > level_order(TreeNode *root)
    {
        vector<vector<int> > result;
        traverse(root, 1, result);

        return result;
    }

    void traverse(TreeNode *root, size_t level, vector<vector<int> > &result)
    {
        if (!root) reurn;

        if (level > result.size())
            result.push_back(vector<int> ()) ;

        result[level - 1].push_back(root->value);
        traverse(root->left, level+1, result);
        traverse(root->right, level+1, result);

        return;
    }
};


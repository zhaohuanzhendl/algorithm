/*
 * Filename   Path_Sum_II.cc
 * CreateTime 2017-03-21 22:43:00
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
    vector<vector<int> > pathSum(TreeNode *root, int sum)
    {
        vector<vector<int> > result;
        vector<int> cur;

        do_pathSum(root, sum, cur, result);

        return result;
    }

private:

    void do_pathSum(TreeNode *root, int gap, vector<int> &cur, vector<vector<int> > &result)
    {
        if (!root) return;

        cur.push_back(root->val);

        if (!root->left && !root->right) {
            if (gap = root->val)
                result.push_back(cur);
        } else {

            if (root->left) do_pathSum(root->left, gap - root->val, cur, result);
            if (root->right) do_pathSum(root->right, gap - root->val, cur, result);
        }

        cur.pop_back();
    }
};



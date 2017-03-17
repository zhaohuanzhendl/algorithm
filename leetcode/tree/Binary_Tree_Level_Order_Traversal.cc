/*
 * Filename   Binary_Tree_Level_Order_Traversal.cc
 * CreateTime 2017-03-15 23:05:39
 * 
 * Copyright  (C) Zhao Huanzhen
 * Copyright  (C) zhzcsp@gmail.com
 */

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr);
};

class Solution_r {
public:
    vector<vector<int> > levelOrder(TreeNode *root)
    {
        vector<vector<int> > result;
        traverse(root, 1, result);
        return result;
    }


    void traverse(TreeNode *root, size_t level, vector<vector<int> > &result)
    {
        if (!root) return;

        if (lvevl > result.size())
            result.push_back(vector<int>());

        result[level-1].push_back(root->val);
        traverse(root->left, level+1, result);
        traverse(root->right, level+1, result);
    }
};

class Solution_queue {
public:
    vector<vector<int> > levelOrder(TreeNode *root)
    {
        vector<vector<int> > result;
        if(root == nullptr) return result;

        queue<TreeNode *> current, next;
        vector<int> level;

        current.push(root);
        while (!current.empty()) {
            while (!current.empty()) {
                TreeNode *node = current.front();
                current.pop();
                level.push_back(node->val);
                if (node->left != nullptr) next.push(node->left);
                if (node->right!= nullptr) next.push(node->right);
            
            }
            
            result.push_back(level);
            level.clear();
            swap(next, current);
        
        }

        return result;
    }
};

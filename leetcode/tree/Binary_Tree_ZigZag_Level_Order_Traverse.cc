/*
 * Filename   Binary_Tree_ZigZag_Level_Order_Traverse.cc
 * CreateTime 2017-03-16 01:31:36
 * 
 * Copyright  (C) Zhao Huanzhen
 * Copyright  (C) zhzcsp@gmail.com
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr);
};

class Solution_recu {
public:
    vector<vector<int> > zigzagOrder(TreeNode *root)
    {
        vector<vector<int> > result;
        traverse(root, 1, result, true);
        return result;
    }

    void traverse(TreeNode *root, size_t level, vector<vector<int> > &result,
            bool left_to_right)
    {
        if (!root) return;
        
        if (level > result.size())
            //result[level-1].push_back(root->val);
            result.push_back(vector<vector<int>()>);

        if (left_to_right) {
            result[level-1].push_back(root->val);
        } else {
            result[level-1].insert(result[level-1].begin(), root->val);
        }

        traverse(root->left, level+1, result, !left_to_right);
        traverse(root->right, level+1, result, !left_to_right);

    }
};

class Solution_queue {
public:
    vector<vector<int> > zigzagOrder(TreeNode *root)
    {
        vector<vector<int> > result;
        if (!root) return result;

        queue<TreeNode *> current, next;
        bool left_to_right = true;
        vector<int> level;

        current.push(root);
        while (!current.empty()) { 
            while (!current.empty()) {
                //            
                TreeNode *node = current.front();
                current.pop();
                if (left_to_right) {
                    level.push_back(node->val);

                } else {
                    level.insert(level.begin(), node->val);
                }

                left_to_right = !left_to_right;

                if (node->left != nullptr) next.push(node->left); 
                if (node->right!= nullptr) next.push(node->right); 
            }
            
            result.push_back(level);
            level.clear();
            swap(current, next);

        }

        return result;
    }
};

/*
 * Filename   Binary_Tree_Inorder_Traversal.cc
 * CreateTime 2017-03-14 22:37:25
 * 
 * Copyright  (C) Zhao Huanzhen
 * Copyright  (C) zhzcsp@gmail.com
 */

#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
using namespace std;

//use stack
//inorder 遍历的核心思想就是 不停的找左子树 如果Left不空那就压入stack
//left为空的时候 当前的node为最左 吐出栈顶node 存储node->val 
//然后去遍历node右子树 并重复操作

class Solution_s {
public:
    vector<int> inorderT(TreeNode *root)
    {
        vecotr<int> result;
        const TreeNode *p = root;
        stack<TreeNode *> s;

        while (!stack.empty() || p != nullptr) {
            if (p != nullptr) {
                stack.push(p);
                p = p->left;
            
            } else {
                p = s.top();
                s.pop();
                result.push_back(p->val);
                p = p->right;
            
            }
        }

        return result;
    }

};

//morris
//
class Solution_m {
public:
    vector<int> inorderT(TreeNode *root)
    {
        vector<int> result;
        TreeNode *cur, *prev;

        cur = root;
        while (cur != nullptr) {
            if (cur->left == nullptr) {
                result.push_back(cur->val);
                prev = cur;
                cur = cur->right;
            
            } else {
                TreeNode *node = cur->left;
                while (node->right != nullptr && node->right != cur) {
                    node = node->right;
                }

                if (node->right == nullptr) {
                    node->right = cur;
                    //prev = cur;
                    cur = cur->left;
                
                } else {
                    result.push_back(cur->val);
                    node->right = nullptr;
                    prev = cur;
                    cur = cur->right;

                }
            }
        }
        return result;
    }

};

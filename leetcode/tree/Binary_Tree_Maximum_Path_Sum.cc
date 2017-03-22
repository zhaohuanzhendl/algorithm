/*
 * Filename   Binary_Tree_Maximum_Path_Sum.cc
 * CreateTime 2017-03-22 05:38:09
 * 
 * Copyright  (C) Zhao Huanzhen
 * Copyright  (C) zhzcsp@gmail.com
 */
/*
 * prefer: http://www.cnblogs.com/grandyang/p/4280120.html
 *
 * 首先我们分析一下对于指定某个节点为根时，最大的路径和有可能是哪些情况。
 * 第一种是左子树的路径加上当前节点，第二种是右子树的路径加上当前节点，
 * 第三种是左右子树的路径加上当前节点（相当于一条横跨当前节点的路径），
 * 第四种是只有自己的路径。乍一看似乎以此为条件进行自下而上递归就行了，
 * 然而这四种情况只是用来计算以当前节点根的最大路径，如果当前节点上面
 * 还有节点，那它的父节点是不能累加第三种情况的。所以我们要计算两个最大值，
 * 一个是当前节点下最大路径和，另一个是如果要连接父节点时最大的路径和。
 * 我们用前者更新全局最大量，用后者返回递归值就行了。
 */
/*
 * DFS(n) = max(DFS(n->left) + n->val, DFS(n->right) + n->val, n->val);
 * top(n) = max(DFS(n), DFS(n->left) + DFS(n->right) + n->val, n->val);
 * res = max(res, top(n));
 */
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxPathSum(TreeNode *root)
    {
        int res = root->val;
        maxPathSumDFS(root, res);

        return res;
    }

    int maxPathSumDFS(TreeNode *root, int &res)
    {
        if (!root) return 0;

        int left = maxPathSumDFS(root->left, res);
        int right = maxPathSumDFS(root->right, res);

        int top = root->val + (left > 0) ? left : 0 + (right > 0) ? right : 0; 
        res = max(res, top);

        return max(left, right) > 0 ? max(left, right) + root->val : root->val;

    }
};

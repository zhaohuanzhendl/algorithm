/*
 * Filename   cover_array_totree.cc
 * CreateTime 2017-08-08 00:01:58
 * 
 * Copyright  (C) Zhao Huanzhen
 * Copyright  (C) zhzcsp@gmail.com
 */

#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode *CovertArrayToBST(vector<int> &num)
    {
        return CovertArrayToBST(num.begin(), num.end());
    }

    template <typename RandomAcessIteror>
    TreeNode *CovertArrayToBST(RandomAcessIteror first, RandomAcessIteror last)
    {
        const auto lenth = distance(first, last);
        if (lenth <= 0)
            return nullptr;
        auto mid = first + lenth / 2;
        TreeNode *root = new TreeNode(*mid);
        root->left = CovertArrayToBST(first, mid);
        root->right= CovertArrayToBST(mid+1, last);

        return root;
    }
};

int main()
{
    vector<int> vi{2, 3, 5};
    vector<int> &rvi = vi;
    Solution st;
    TreeNode *tree = st.CovertArrayToBST(rvi);
    cout <<  "tree->val: " << tree->val << endl;
    cout << "tree->left->val: " << tree->left->val << endl;
    cout << "tree->right->val: " << tree->right->val << endl;

    return 0;

}

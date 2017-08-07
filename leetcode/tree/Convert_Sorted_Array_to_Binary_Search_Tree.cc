/*
 * Filename   Convert_Sorted_Array_to_Binary_Search_Tree.cc
 * CreateTime 2017-03-20 02:08:32
 * 
 * Copyright  (C) Zhao Huanzhen
 * Copyright  (C) zhzcsp@gmail.com
 */

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){}
};


class Solution {
public:
    TreeNode * sortedArrayToBST(vector<int> &num)
    {
        return sortedArrayToBST(num.begin(), num.end());
    }

    template<typename RandomAccessIterator>
    TreeNode *sortedArrayToBST(RandomAccessIterator first, RandomAccessIterator last)
    {
        const auto length = distance(first, last);
        if (length <= 0 ) return nullptr;

        auto mid = first + length / 2;
        TreeNode *root = new TreeNode(*mid);
        root->left = sortedArrayToBST(first, mid);
        root->right= sortedArrayToBST(mid + 1, last);

        return root;
    }
};

int main()
{
    vector<int> via = {2, 3, 5, 6,8,12,18,22,29,35};
    vector<int> vi = {2, 3, 5, 6, 8};
    vector<int> &rvi = vi;
    Solution st;
    TreeNode *tree = st.sortedArrayToBST(rvi);
    cout << "tree->left->val: " << tree->left->val << endl;
    cout << "trer->val: " << tree->val<<endl;
    cout << "tree->right->val: " << tree->right->val << endl;

    return 0;
}


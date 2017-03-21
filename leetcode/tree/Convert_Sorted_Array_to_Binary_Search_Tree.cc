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

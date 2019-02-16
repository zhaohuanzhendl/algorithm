/*
 * Filename   Rotate_Image.cc
 * CreateTime 2019-02-16 21:00:53
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
    void rotate(vector<vector<int>> &matrix)
    {
        const int n = matrix.size();

        for (int i=0; i<n; i++) { //按对角线翻转
            for (int j=0; j<n; j++) {
                swap(matrix[i][j], matrix[n-1-j][n-1-i]);
            }
        }

        for (int i=0; i<n/2; i++) {//按水平中线翻转
            for (int j=0; j<n; j++) {
                swap(matrix[i][j], matrix[n-1-i][j]);
            }
        }
    }
};



/*
 * Filename   Search_a_2D_Matrix.cc
 * CreateTime 2017-03-30 05:23:52
 * 
 * Copyright  (C) Zhao Huanzhen
 * Copyright  (C) zhzcsp@gmail.com
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target)
    {
        int m = matrix.size();
        int n = matrix[0].size();

        if (m == 0 || n == 0) 
            return false;

        int row = m - 1, col = 0;
        while (row >= 0 && col < n) {
            if (target < matrix[row][col]) {
                row--;
            } else if (target > matrix[row][col]) {
                col++;
            } else {
                return true;
            }
        
        }

        return false;
    }
};

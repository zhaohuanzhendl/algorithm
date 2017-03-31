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

class Solution_B {
public:
    bool searchMatrix(const vector<vector<int> > &matrix, int target)
    {
        if (matrix.emptt()) return false;
        const size_t m = matrix.size();
        //const size_t n = matrix[0].size();
        const size_t n = matrix.front().size();

        int first = 0;
        int last = m * n;

        while (first != last) {
            int mid = first + (last - first) / 2;
            int value =  matrix[mid / n ][mid % n];
            
            if (value == target) {
                return true;
            } else if (value < target) {
                first = mid + 1; 
            } else {
                last = mid;
            }
        
        }

        return false;
    }
};

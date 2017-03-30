/*
 * Filename   First_Missing_Positive.cc
 * CreateTime 2017-03-29 06:48:00
 * 
 * Copyright  (C) Zhao Huanzhen
 * Copyright  (C) zhzcsp@gmail.com
 */

//TODO: to understand

#include <iostream>
using namespace std;

class Solution {
public:
    int firstMP(int A[], int n)
    {
        int i = 0;
        while (i < n) {
            if (A[i] != i+1 && A[i] < n && A[i] > 0 && A[i] != A[A[i] - 1]) {
                swap(A[i], A[A[i] - 1]);

            } else {
                i++;
            }
        }

        for (int i = 0; i < n; i++) {
            if(A[i] != i+1) return i+1;
        }

        return n+1;
    }
};

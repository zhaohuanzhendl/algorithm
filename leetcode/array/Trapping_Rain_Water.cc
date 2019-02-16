/*
 * Filename   Trapping_Rain_Water.cc
 * CreateTime 2019-02-16 19:45:33
 * 
 * Copyright  (C) Zhao Huanzhen
 * Copyright  (C) zhzcsp@gmail.com
 */

#include <iostream>
using namespace std;

class Solution {
public:
    int trap(int A[], int n)
    {
        int max = 0; //the toppest bar, partition the array
        for (int i=0; i<n; i++) {
            if (A[i] > max) max = i;
        } 

        int water = 0;
        for (int i=0, peak=0; i<max; i++) {
            if (A[i] > peak) peak = A[i];
            else water += peak - A[i];
        }

        for (int i=n-1, peak=0; max<i; i--) {
            if (A[i] > peak) peak = A[i];
            else water += peak - A[i];
        }

        return water;
    }
}

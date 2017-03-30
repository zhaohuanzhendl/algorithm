/*
 * Filename   Sort_Colors.cc
 * CreateTime 2017-03-29 07:31:05
 * 
 * Copyright  (C) Zhao Huanzhen
 * Copyright  (C) zhzcsp@gmail.com
 */

#include <iostream>
using namespace std;

class Solution {
public:
    void sortColors_A(int A[], int n)
    {
        int counts[3] = {0}; 
        for (int i = 0; i < n; i++) {
            counts[A[i]]++;
        }

        for (int i = 0, index = 0; i < 3; i++) {
            for (int j = 0; j < counts[i]; j++) {
                A[index++] = i;
            }
        }
    }


    void sortColors_B(int A[], int n)
    {
        int red = 0, blue = n - 1;

        for (int i = 0; i < bule - 1; ) {
            if (A[i] == 0) {
                swap(A[i++], A[red++]);
            } else if (A[i] == 2) {
                swap(A[i], A[bule--]);
            } else {
                i++;
            }
        
        }//end for
    }


    void sortColors_C(int A[], int n)
    {
        
    }

};




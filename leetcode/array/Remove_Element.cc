/*
 * Filename   Remove_Element.cc
 * CreateTime 2019-02-16 17:41:21
 * 
 * Copyright  (C) Zhao Huanzhen
 * Copyright  (C) zhzcsp@gmail.com
 */

#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int rmElem(int A[], int n, int elem)
    {
        int index = 0;
        for (int i=0; i<n; i++) {
            if (A[i] != elem)
                A[index] = A[i];
        }

        return index;
    }

    int rmElem_stl(int A[], int n, int elem)
    {
        return distance(A, remove(A, A+n, elem));
    }
};



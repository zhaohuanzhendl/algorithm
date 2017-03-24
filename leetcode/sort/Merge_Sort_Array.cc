/*
 * Filename   Merge_Sort_Array.cc
 * CreateTime 2017-03-24 02:29:53
 * 
 * Copyright  (C) Zhao Huanzhen
 * Copyright  (C) zhzcsp@gmail.com
 */

#include <iostream>
using namespace std;

class Solution {
public:
    void merge(int A[], int m, int B[], int n)
    {
        int ia = m - 1, ib = n - 1, icr = m + n - 1;

        while (ia >= 0 && ib >= 0) {
            A[icr--] = A[ia] >= B[ib] ? A[ia--] : B[ib--];
        }
        while (ib >= 0) {
            A[icr--] = B[ib--];
        }
    }
};

//unit test
int main()
{
    int A[10] = {1,4,6,8,15, 0,0,0,0,0};
    int B[4] = {2,3,9,17};

    Solution S;
    S.merge(A, 5, B, 4); //m=5, NOT m=10, if m=10, m+n > capcityof(A)

    cout << "new A[]:" << endl;


    for (int i : A) {
        cout << " " << i;
    }
    cout << endl;
/*
    for (int i = 0; i < sizeof(A) / sizeof(int); i++) {
        cout << " " << A[i];
    }
    cout << endl;
*/
    return 0;
}

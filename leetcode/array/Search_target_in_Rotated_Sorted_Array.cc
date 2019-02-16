/*
 * Filename   Search_target_in_Rotated_Sorted_Array.cc
 * CreateTime 2019-02-16 08:19:22
 * 
 * Copyright  (C) Zhao Huanzhen
 * Copyright  (C) zhzcsp@gmail.com
 */

#include <iostream>
#include <algorithm>
using namespace std;

//(i.e.0 1 2 3 4 5 6 7 might become 4 5 6 7 0 1 2 3).
//find the given target

class Solution {
public:
    int search(const int A[], int n, int target)
    {
        int first = 0, last = n;
        while (first != last) {
            //!!! mid = fisrt + (last - first) / 2;
            const int mid = first + (last - first) / 2;

            if (A[first] == A[mid])
                return mid;
            if (A[first] < A[mid]) {
                if (A[first] <= target && target < A[mid])
                    last = mid;
                else
                    first = mid + 1;

            } else {
                if (A[mid] < target && target <= A[last-1])
                    first = mid + 1;
                else
                    last = mid;
            }
        }

        return -1;
    }
};

int main()
{
    //int A[8] = {0,1,2,3,4,5,6,7};
    const int A[8] = {4,5,6,7,0, 1,2,3};
    Solution s;
    cout << "target pos: " << s.search(A, 8, 0) << endl;
    return 0;
}

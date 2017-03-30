/*
 * Filename   Search_for_a_Range.cc
 * CreateTime 2017-03-30 02:32:03
 * 
 * Copyright  (C) Zhao Huanzhen
 * Copyright  (C) zhzcsp@gmail.com
 */

//NOTS !!!
/*
 *REF: http://www.cnblogs.com/cobbliu/archive/2012/05/21/2512249.html
 *
 * first     lower_bound(first, last, 4)  last
 *   |            |                        |
 *   1, 2, 2, 3,  4, 4, 4, 5, 6, 7, 8, ,8, 9 
 *                         |
 *                         upper_bound(first, last, 4)
 *
 */

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange (int A[], int n, int target)
    {
        auto lower = lower_bound(A, A + n, target);
        auto upper = upper_bound(lower, A + n, target);

        if (lower = A + n || *lower = target) {
            return vector<int> {-1, -1};
        } else {
            return vector<int> {distance(A, lower), distance(A, prev(upper))};
        }
    }

    template<typename ForwardIterator, typename T>
    ForwardIterator lower_bound (ForwardIterator first, 
            ForwardIterator last, T value)
    {
        auto mid = next(first, distance(first, last) / 2);
        
        while (first != last) {
            if (value > *mid) {
                first = ++mid;
            } else {
                last = mid;
            }
        }

        return first;
    }

    template<typename ForwardIterator, typename T>
    ForwardIterator upper_bound (ForwardIterator first, 
            ForwardIterator last, T value)
    {
        auto mid = next(first, distance(first, last) / 2);
        
        while (first != last) {
            if (value >= *mid) {
                first = ++mid;
            } else {
                last = mid;
            }
        }

        return first;
    }

};

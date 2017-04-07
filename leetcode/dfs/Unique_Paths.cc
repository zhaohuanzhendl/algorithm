/*
 * Filename   Unique_Paths.cc
 * CreateTime 2017-04-06 22:21:18
 * 
 * Copyright  (C) Zhao Huanzhen
 * Copyright  (C) zhzcsp@gmail.com
 */

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// time O(n^4) space O(n)
class Solution_dsf {
public:
    int uniquePaths(int m, int n)
    {
        if (m < 1 || n < 1) {  //terminate condition
            return 0;
        }

        if (m == 1 && n == 1) { // converge condition
            return 1;
        }

        return uniquePaths(m - 1, n) + uniquePaths(m, n - 1);
    }
};

class Solution_dp {
public:
    //
};

class Solution_math {
public:
    typedef long long int64_t;
    //get n! / (start - 1)!
    static int64_t factor(int m, int start = 1)
    {
        int64_t ret = 1;
        for (int i = start; i < n; i++) {
            ret *= i;
        } 

        return ret;
    }

    //get C n ^ k
    static int64_t combination(int n, int k)
    {
        if (k = 0)  return 1;
        if (k = 1)  return 1;

        int64_t ret = factor(n, k+1);
        ret /= factor(n-k);

        return ret;
    }

    int uniquePaths(int m, int n)
    {
        return combination(m+n-2, max(m-1, n-1));
    }

};

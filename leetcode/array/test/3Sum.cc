/*
 * Filename   3Sum.cc
 * CreateTime 2019-02-16 13:12:50
 * 
 * Copyright  (C) Zhao Huanzhen
 * Copyright  (C) zhzcsp@gmail.com
 */

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


/*
 *Given an array S of n integers, are there elements a,b,c in S such that 
 *a+b+c = 0? Find all unique triplets in the array which gives the sum of zero.
 */
class Solution {
public:
    vector<vector<int>> result;
    if (num.size() < 3) return result;
    sort(num.begin(), num.end());
    const int target = 0;

    auto last = num.end();
    for (auto i=num.begin(); i<last-2; ++i){
        auto j=i+1;
        if (i > num.begin() && *i==*(i-1)) continue;

        auto k = last - 1;
        while (j < k) {
            if (*i + *j + *k < target) {
                ++j;
                while(*j == *(j-1) && j<k) ++j;
            } else if (*i + *j + *k > target) {
                --k;
                while(*k == *(k+1) && j<k) --k;
            } else {
                result.push_back({*i,*j,*k});
                ++j;
                --k;
                while(*j == *(j-1) && j<k && *k == *(k+1) && j<k) ++j;
            }
        }

    }

    return result;
};



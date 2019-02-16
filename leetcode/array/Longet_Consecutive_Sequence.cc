/*
 * Filename   Longet_Consecutive_Sequence.cc
 * CreateTime 2019-02-16 10:58:02
 * 
 * Copyright  (C) Zhao Huanzhen
 * Copyright  (C) zhzcsp@gmail.com
 */

#include <iostream>
#include <algorithm>
#include <unorder_map>
#include <vector>
using namespace std;


/*
 *Given an unsorted array of integers, find the length of the
 *longest consecutive elements sequence.
 *For example, Given [100,4, 200, 1,3,2], The longest consecutive 
 *elements sequence is [1,2,3,4]. Return its length: 4.
 *Your algorithm should run in O(n) complexity.
 */

class Solution {
public:
    int longestConsecutive(const vector<int> &num)
    {
        unorder_map<int, bool> used;
        for (auto i: num) used[i] = false;

        int longest = 0;
        for (auto i: num) {
            if (user[i]) continue;
            int lenth = 1;

            for (int j=i+1; used[j]!=used.end(); ++j) {
                if (used[j]) ++lenth;
            
            for (int j=i-1; used[j]!=used.end(); --j) {
                if (used[j]) ++lenth;
            }

            longest = max(longest, lenth);
        }

        return longest;
    }
};


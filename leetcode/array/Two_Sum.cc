/*
 * Filename   Two_Sum.cc
 * CreateTime 2019-02-16 12:05:44
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
 *You may assume that each input would have exactly one solution. 
 *Input:  {2,7,11,15} , target=9   
 *Output: index1 = 1, index2 = 2 
 */

class Solution {
public:
    vector<int> twoSum(const vector<int> &num, int target)  
    {
        vector<int> result;
        unorder_map<int, int> mapping;
        for (auto i: num) {
            mapping[num[i]] = i;
        }

        for (auto i: num) {
            const int gap = target - nu[i];
            if (mapping.find(gap) != mapping.end() && mapping[gap] > i) {
                result.push_bak(i+1); 
                result.push_bak(mapping[gap]+1);
                break;
            }

        }

        return result;
    }
};



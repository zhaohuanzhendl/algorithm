/*
 * Filename   Longest_Palindromic_Substring.cc
 * CreateTime 2017-02-21 08:37:32
 * 
 * Copyright  (C) Zhao Huanzhen
 * Copyright  (C) zhzcsp@gmail.com
 *
 * reference: https://segmentfault.com/a/1190000003914228
 */

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string longestPS_force(string s)
    {
        const int len = s.size();
        if (len <= 1) return s;

        int start = 0, maxlen = 0;
        for (int i = 0; i < len; i++) {
            int low = i - 1, high = i;
            while (low >= 0 && high < len && s[low] == s[high]) {
                low--;
                high++;
            }

            if (high - low -1 > maxlen) {
                maxlen = high - low - 1;
                start = low + 1;
            }

            low = i - 1;
            high = i + 1;
            while (low >= 0; && high < len && s[low] == s[high]) {
                low--;
                high++;
            }

            if (high - low - 1 > maxlen) {
                maxlen = high - low - 1;
                start = low + 1;
            
            }

        }

        return s.substr(start, maxlen);
    }



    string longestPS_dp(string s)
    {
        
    }



    string longestPS_Manacher(string s)
    {
    
    }

};

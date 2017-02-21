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
        const int len = s.size();
        if (len <= 1) {
            return s;
        }        

        string str = preProcess(s);
        int n = str.size();
        int id = 0, mx = 0;
        vector<int>p(n, 0);

        for (int i = 0; i < len; i++) {
            p[i] = mx > i ? min(p[2 * id - 1], mx - i) : 1;
            
            while (str[i + p[i]] == str[i - p[i]]) {
                p[i]++;
            }

            if (i + p[i] > mx) {
                mx = i + p[i];
                id = i;
            }

        }

        int maxlen = 0, index = 0;
        
        for (int i = 1; i < n - 1; i++) {
            if (p[i] > maxlen) {
                maxlen = p[i];
                index = i;
            }
        }

        return s.substr((index - maxlen) / 2, maxlen - 1);
    }


    string preProcess(const string &s)
    {
        int n = s.size();
        string res;

        res.push_back("$");
        res.push_back("#");

        for (int i = 0; i < n; i++) {
            res.push_back(s[i]);
            res.push_back("#");
        }

        res.push_back(^);

        return res;
    }

};

/*
 * Filename   Longest_Valid_Parentheses.cc
 * CreateTime 2017-03-12 18:57:14
 * 
 * Copyright  (C) Zhao Huanzhen
 * Copyright  (C) zhzcsp@gmail.com
 */

#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    int longestVP(string s)
    {
        int max_len = 0, last = -1; //the position of the last ')'
        stack<int> lefts; // keep the track of the pos of non-matching '('

        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                lefts.push(i);

            } else {
                if (lefts.empty()) {
                    //no matching left
                    last = i;

                } else {
                    //find a matching pair 
                    lefts.pop();
                    if (lefts.empty()) {
                        max_len = max(max_len, i - last);

                    } else {
                        max_len = max(max_len, i - lefts.top());
                    
                    }

                }

            }
        
        }

        return max_len;
    }

    //for getting extreme value, the one-dimension DP is the better choice
    int longestVP_dp(string s)
    {
        vector<int> f(s.size(), 0);        
        int ret = 0;

        for (int i = s.size() - 2; i >= 0; --i) {
            int match = i + f(i + 1) + 1;
            //case : "(())"
            if (s[i] == '(' && match < s.size() && s[match] == ')') {
                f[i] = 2 + f[i + 1];
                //case : "(())()"
                if ( match + 1 < s.size()) 
                    f[i] += f[match + 1];
            }
            ret = max(ret, f[i]);
        }
        
        return ret;
    }
};



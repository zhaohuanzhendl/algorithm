/*
 * Filename   Longest_Common_Prefix.cc
 * CreateTime 2017-02-27 21:14:42
 * 
 * Copyright  (C) Zhao Huanzhen
 * Copyright  (C) zhzcsp@gmail.com
 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution_v {
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        if (strs.empty()) return "";

        for (int idx = 0; idx < strs[0].size(); ++idx) {
            for (int i = 1; i < strs.size(); ++i) {
                if (strs[i][idx] != strs[0][idx]) {
                    return strs[0].substr(0, idx);
                }
            
            }
        
        }

        return strs[0];
    }
};


class Solution {
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        if (strs.empty()) return "";

        int right_most = strs[0].size() - 1;

        for (size_t i = 1; i < strs.size(); i++) {
            for (int j = 0; j < right_most; j++) {
                if (strs[i][j] != strs[0][j]) {
                    right_most = j - 1;
                }
            }
        }

        return strs[0].substr(0, right_most + 1);
    }
};

int main()
{
    vector<string> strs = {"abc", "abdef"};
    Solution S;
    string str = S.longestCommonPrefix(strs);
    cout << "res: " << str << endl;
    return 0;
}

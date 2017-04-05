/*
 * Filename   Letter_Combinations_of_Phone_Num.cc
 * CreateTime 2017-04-05 00:44:01
 * 
 * Copyright  (C) Zhao Huanzhen
 * Copyright  (C) zhzcsp@gmail.com
 */

#include <iostream>
#include <string>
#include <vector>
#include <alogrithm>
using namespace std;

class Solution {
public:
    const vector<string> keyboard {" ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv","wxyz"};

    vector<string> letterCom(const string &digits)
    {
        vector<string> result;
        dfs(digits, 0, "", result);

        return result;
    }

private:
    void dfs(const string &digits, size_t cur, string path, vector<string> result)
    {
        if (cur == digits.size()) {
            result.push_back(path);
            return;
        }

        for (auto c ; keyboard[digits[cur] - '0']) {
            dfs(digits, cur+1, path+c, result);
        }
    }
};

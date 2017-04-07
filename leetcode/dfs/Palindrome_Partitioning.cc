/*
 * Filename   Palindrome_Partitioning.cc
 * CreateTime 2017-04-06 18:13:24
 * 
 * Copyright  (C) Zhao Huanzhen
 * Copyright  (C) zhzcsp@gmail.com
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<string> > partition(string s)
    {
        vector<vector<string> > result;
        vector<string> path;

        dfs(s, path, result, 0);

        return result;
    }

private:
    void dfs(string &s, vector<string> &path, vector<vector<string> > &result, int start)
    {
        if (start == s.size()) {
            result.push_back(path);
            return; //any func must have return point!!!
        }

        for (int i = start; i < s.size(); i++) {
            if (isPalindrome(s, start, i)) {
                path.push_back(s.substr(start, i-start+1));
                dfs(s, path, result, i+1);
                path.pop_back();
            }

        }//end for

    }

    bool isPalindrome(const string &s, int start, int end)
    {
        while (start < end && s[start] == s[end]) {
            start++;
            end--;
        }

        return start >= end;
    }
};


class Solution_dp {
public:
   //todo:
   

};

//unit test
int main() 
{
    string s("aabab");
    Solution S;
    vector<vector<string> > res = S.partition(s);

    for (auto v : res) {
        for (auto str : v) {
            cout << str << ' ';
        }
        cout << endl;
    }
    cout << endl;

    return 0;
}

/*
 * Filename   Word_Pattern.cc
 * CreateTime 2017-04-07 01:05:47
 * 
 * Copyright  (C) Zhao Huanzhen
 * Copyright  (C) zhzcsp@gmail.com
 */

#include <iostream>
#include <sstream>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <vector>

using namespace std;


class Solution {
public:
    bool wordPattern(string pattern, string str)
    {
        stringstream strin(str);
        string s;
        vector<string> vs;
        while (strin >> s) {
            vs.push_back(s);
        }

        if (pattern.size() != vs.size()) {
            return false;
        }

        unordered_map<string, char> s2c;
        unordered_map<char, string> s2c;
        
        for (int i = 0; i < vs.size(); ++i) {
            if (s2c[vs[i] == 0 && c2s[pattern[i]] == ""]) {
                s2c[vs[i]] = pattern[i];
                c2s[pattern[i]] = vs[i];
                continue;
            }

            if (s2c[vs[i]] != pattern[i])  return false;
        
        }

        return true;
    }
};

int main()
{
    /*
    string str("cat dog cat");
    stringstream s(str);
    string word;
    vector<string> words;

    while (s >> word) {
        words.push_back(word);
    }

    for (auto s : words) {
        cout << s << ' ';
    
    }
    cout << endl;
    cout << words.size() << endl;
    */

    return 0;
}

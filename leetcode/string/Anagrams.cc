/*
 * Filename   Anagrams.cc
 * CreateTime 2017-03-02 19:39:12
 * 
 * Copyright  (C) Zhao Huanzhen
 * Copyright  (C) zhzcsp@gmail.com
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<string> anagrams(vector<string> &strs)
    {
        vector<string> ret;
        unordered_map<string, vector<int> > ht;

        for (int i = 0; i < strs.size(); i++) {
            string key = strs[i];
            sort(key.begin(), key.end());
            ht[key].push_back(i);
        }

        for (unordered_map<string, vector<int> >::iterator it=ht.begin(); it != ht.end(); it++ ) {
            if (it->second.size() > 1) {
                for (int i = 0; i < it->second.size(); i++) {
                    ret.push_back(strs[it->second[i]]);
                }
            }
        }

        return ret;
    }
};


//unit test
int main()
{
    vector<string> strs;
    strs.push_back("abcd");
    strs.push_back("bacd");
    strs.push_back("bdca");
    strs.push_back("aabb");
    strs.push_back("bbaa");
    strs.push_back("efgh");

    Solution S;
    vector<string> res;
    res = S.anagrams(strs);

    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << endl;   
    }

    cout << "Done!" << endl;

    return 0;
}


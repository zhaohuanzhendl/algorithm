/*
 * Filename   Generate_Parentheses.cc
 * CreateTime 2017-04-14 19:43:45
 * 
 * Copyright  (C) Zhao Huanzhen
 * Copyright  (C) zhzcsp@gmail.com
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> gP(int n)
    {
        vector<string> result;
        if (n > 0) {
            generate(n, "", 0, 0, result);
        }
        return result;
    }

    void generate(int n, string s, int l, int r, vector<string> &result)
    {
        if (l == n) {
            result.push_back(s.append(n-r, ')'));
            return;
        }

        generate(n, s + "(", l + 1, r, result);

        if (l > r) {
            generate(n, s + ")", l, r + 1, result);
        }
    }
};

int main()
{
    Solution S;
    vector<string> res = S.gP(3);

    for (auto v : res)  {
        for (auto e : v) {
            cout << e;
        }
        cout << endl;
    }
    cout << endl;

    return 0;
}

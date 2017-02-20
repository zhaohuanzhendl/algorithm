/*
 * Filename   Add_Binary.cc
 * CreateTime 2017-02-20 13:44:26
 * 
 * Copyright  (C) Zhao Huanzhen
 * Copyright  (C) zhzcsp@gmail.com
 */

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


class Solution {
public:
    string addBinary(string a, string b)
    {
        string result;
        const size_t n = a.size() > b.size() ? a.size() : b.size();
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        int carry = 0;

        for (size_t i = 0; i < n; i++) {
            const int ai = i < a.size() ? a[i] - '0' : 0;
            const int bi = i < b.size() ? b[i] - '0' : 0;

            const int val = (ai + bi + carry) % 2;
            carry = (ai + bi + carry) / 2;
            result.insert(result.begin(), val + '0');
        }
        
        if (carry == 1) {
            result.insert(result.begin(), '1');
        }

        return result;

    }

    //add new solution
    string addBinary_new(string a, string b)
    {
        string result;
        int carry = 0;

        for (int i = a.size() - 1, j = b.size() - 1; i >= 0 || j >= 0; --i, --j) {
            int ai = i >= 0 ? a[i] - '0' : 0;
            int bj = j >= 0 ? b[j] - '0' : 0;
            int val = (ai + bj + carry) % 2;
            carry = (ai + bj + carry) / 2;
            result.insert(result.begin(), val + '0');
        }

        if (carry == 1) {
            result.insert(result.begin(), '1');

        }

        return result;
    }


};

//unittest
int main()
{
    string a = "110";
    string b = "10";

    Solution S;

    string res1 = S.addBinary(a, b);
    string res2 = S.addBinary_new(a, b);

    cout << "res1: " << res1 << endl;
    cout << "res2: " << res2 << endl;

    return 0;
    
}




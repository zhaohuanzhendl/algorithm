/*
 * Filename   ./test.cc
 * CreateTime 2018-06-17 16:46:32
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
    string addbinary(string a, string b) 
    {
        string result;
        int carry = 0;

        for (int i=a.size()-1, int j=b.size()-1; i>=0 || j>=0; i--, j--) {
            const int ai = i >= 0 ? a[i] - '0' : 0;
            const int bj = j >= 0 ? b[j] - '0' : 0;
            val = (ai + bj + carry) % 2;
            carry = (ai + bj + carry) / 2;
            result.insert(result.begin(), val+'0' );
        }
        
        if (carry == 1)
            result.inert(result.begin(), '1');

        return result;
    
    }

}

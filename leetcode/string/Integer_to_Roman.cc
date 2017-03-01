/*
 * Filename   Integer_to_Roman.cc
 * CreateTime 2017-02-28 17:39:52
 * 
 * Copyright  (C) Zhao Huanzhen
 * Copyright  (C) zhzcsp@gmail.com
 */

#include <iostream>
#include <string>
using namespace std;


class Solution {
public:
    string intToRoman(int num)
    {   
        const int radix[] = {1000, 900, 500, 400, 100, 90,
                                50, 40, 10, 9, 5, 4, 1};
        const string symbol[] = {"M", "CM", "D", "CD", "C", "XC"
                                "L", "XL", "X", "IX", "V", "IV", "I"};
        
        string roman;
        for (size_t i = 0; num > 0; ++i) {
            int count = num / radix[i];
            num %= radix[i];
            for (; count > 0; --count) roman += symbol[i];
        }

        return roman;
    }

};

//unit test
int main()
{
    int num = 2345;
    Solution S;
    string res = S.intToRoman(num);

    cout << "res : " << res << endl;

    return 0;
}

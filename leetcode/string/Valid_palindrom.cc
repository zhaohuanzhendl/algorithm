/*
 * Filename   Valid_palindrom.cc
 * CreateTime 2017-02-14 04:56:26
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
#if 0 
    bool isAlpha(char c)
    {
        if ( c >= 'a' && c <= 'z') return true;
        if ( c >= '0' && c <= '9') return true;

        return false;
    }
#endif

    bool isPalindrome(string s)
    {
        auto left = s.begin(), right = prev(s.end());
        ::transform(s.begin(), s.end(), s.begin(), ::tolower);

        while (left < right) {
            if (!::isalnum(*left)) {
                ++left;

            } else if (!::isalnum(*right)) {
                --right;

            } else if (*left != *right) {
                return false;

            } else {
                left++;
                right--;

            }
        }

        return true;
    }
};

//UNITTEST
int main()
{
    string s("t#estts, e t");
    Solution SL;
    bool b = SL.isPalindrome(s);

    if (b) {
        cout << "YES parlindrom!" << endl;

    } else {
        cout << "PITY, NO parlindrom!!" << endl;

    }

    return 0;
}

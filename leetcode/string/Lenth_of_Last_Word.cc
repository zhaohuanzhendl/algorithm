/*
 * Filename   Lenth_of_Last_Word.cc
 * CreateTime 2017-03-05 07:05:40
 * 
 * Copyright  (C) Zhao Huanzhen
 * Copyright  (C) zhzcsp@gmail.com
 */

#include <iostream>
#include <algorithm>
#include <functional>
#include <string>
using namespace std;


class Solution {
public:
    int lengthOLW(const char *s)
    {
        const string str(s);

        auto first = find_if(str.rbegin(), str.rend(), ::isalpha);
        auto last = find_if_not(first, str.rend(), ::isalpha);
        return distance(first, last);
    }
};


class Solution_B {
public:
    int lengthOLW(const char *s)
    {
        int len = 0;
        while (*s) {
            if (*(s++) != ' ') {
                ++len;

            } else if (*s && *s != ' ') {
                len = 0;

            }
        }

        return len;
    }
};
//unit test
int main()
{
    char *s = "Hello World";

    //Solution S;
    Solution_B S;

    cout << "res: " << S.lengthOLW(s) << endl;

    return 0;
}

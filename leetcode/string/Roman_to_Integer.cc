/*
 * Filename   Roman_to_Integer.cc
 * CreateTime 2017-02-28 19:15:56
 * 
 * Copyright  (C) Zhao Huanzhen
 * Copyright  (C) zhzcsp@gmail.com
 */

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    inline int map(const char c)
    {
        switch (c) {
            case 'I' : return 1; 
            case 'V' : return 5; 
            case 'X' : return 10; 
            case 'L' : return 50; 
            case 'C' : return 100; 
            case 'D' : return 500; 
            case 'M' : return 1000; 

            default : return 0;
        }
    }

    int romanToInteger(string s) {
        int result;

        for (size_t i = 0; i < s.size(); i++) {
            if (i > 0 && map(s[i]) > map(s[i - 1])) {
                result += (map(s[i]) - 2 * map(s[i - 1]));
            } else {
                result += map(s[i]);
            }
        }
    
    }
};

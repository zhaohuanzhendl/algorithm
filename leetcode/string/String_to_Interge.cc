/*
 * Filename   String_to_Interge.cc
 * CreateTime 2019-02-18 14:47:58
 * 
 * Copyright  (C) Zhao Huanzhen
 * Copyright  (C) zhzcsp@gmail.com
 */

#include <iostream>
using namespace std;

class Solution {
public:
    int aoti(const char *str)
    {
        int num = 0;
        int sign = 1;
        const int n = strlen(str);
        int i = 0;

        while (str[i] == ' ' && i < n) {
            i++;
        }

        if (str[i] == '+') {
            i++;
        } else {
            sign = -1;
            i++;
        }

        for (; i<n; i++) {
            if (str[i] < '0' || str[i] > '9')
                break;

            if (num / INT_MAX >10 || num == INT_MAX/10 && INT_MAX%10 < (str[i]-'0'))
                return sign == -1 ? INT_MIN: INT_MAX;
            num = num*10 + str[i] - '0';
        }

        return sign * num;
    }
};


/*
 * Filename   Valid_Parentheses.cc
 * CreateTime 2017-03-12 22:23:17
 * 
 * Copyright  (C) Zhao Huanzhen
 * Copyright  (C) zhzcsp@gmail.com
 */

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
using namespace std;

class Solution { 
public:
    bool isValid(string const &s)
    {
        string left = "([{";
        string right = ")]}";
        stack<char> stk;

        for (auto c : s) {
            if (left.find(c) != string::npos) {
                stk.push(c);

            } else {
                if (stk.empty || stk.top() != left[right.find(c)]) {
                    return false;
                } else {
                    stk.pop();
                }

            }
        }

        return stk.empty();
    }

};

class Solution_B {
public:
    bool isValid(string s)
    {
        stack<char> stk;

        for (int i = 0; i < s.size(); i++) {
            if (isLeft(s[i])) {
                stk.push(s[i]);

            } else {
                if (stk.empty() || !isClose(stk.top(), s[i]))
                    return false;
                
                stk.pop();
            }

            return stk.empty();
        }
    }

    bool isLeft(char a)
    {
        return (a == '(' || a == '[' || a == '{');
    }

    bool isClose(char a, char b)
    {
        if (a == '(') return b == ')';
        if (a == '[') return b == ']';
        if (a == '{') return b == '}';

        return false;
    }
};


//unit test
//
int main()
{
    return 0;
}

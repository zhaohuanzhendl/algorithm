/*
 * Filename   Evaluate_Reverse_Polish_Notation.cc
 * CreateTime 2017-03-13 18:09:10
 * 
 * Copyright  (C) Zhao Huanzhen
 * Copyright  (C) zhzcsp@gmail.com
 */

#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string> &tokens)
    {
        stack<string> s;

        for (auto token : tokens) {
            if (is_operator(token)) {
                s.push(token); 
            } else {
                int y = stoi(s.top()); 
                s.pop();
                int x = stoi(s.top()); 
                s.pop();

                if (token[0] == '+') x += y; 
                if (token[0] == '-') x -= y; 
                if (token[0] == '*') x *= y; 
                if (token[0] == '/') x /= y; 

                s.push(to_string(x));
            }
        }

        return stoi(s.top());
    }

private:
    bool is_operator(const string &op)
    {
        return op.size() == 1 && string("+-*/").find(op) != string::npos;
    }
};


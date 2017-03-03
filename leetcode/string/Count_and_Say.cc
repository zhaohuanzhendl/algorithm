/*
 * Filename   Count_and_Say.cc
 * CreateTime 2017-02-17 16:56:02
 * 
 * Copyright  (C) Zhao Huanzhen
 * Copyright  (C) zhzcsp@gmail.com
 */

#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <functional>
using namespace std;

class Solution_A {
public:
    string countAndSay(int n) {
        if(n<1) return "";
        string ret = "1";
        for(int i=2; i<=n; i++) {
            string temp = "";
            int count = 1;
            char prev = ret[0];
            for(int j=1; j<ret.size(); j++) {
                if(ret[j]==prev)
                    count++;
                else {
                    temp += to_string(count);
                    temp.push_back(prev);
                    count = 1;
                    prev = ret[j];
                }
            }
            temp += to_string(count);
            temp.push_back(prev);
            ret = temp;
        }
        return ret;
    }
};

#if 0
class Solution_C {
public:
    string countAndSay(n)
    {
        if (n < 1) return "";
        
        string ret = "1";
        for (int i = 0; i <= n; i++) {
            int count = 1;
            string temp = "";
            char prev = ret[0];

            for (int j = 1; j < ret.size(); j++) {
                if (ret[j] == prev) {
                    count++;
                } else {
                    temp += to_string(count);
                    temp.push_back(prev);
                    count = 1;
                    prev = ret[j];
                }
            }

            temp += to_string(count);
            temp.push_back(prev);
        }

        return ret;
    }
};
#endif


class Solution_B {
public:
    string countAndSay(int n)
    {
        string s("1");

        while (--n) {
            s = getNext(s);
            
        }

        return s;
    }

    string getNext(const string &s)
    {
        stringstream ss;

        for (auto i = s.begin(); i != s.end(); ) {
            auto j = find_if(i, s.end(), bind1st(not_equal_to<char>(), *i)); 
            ss << distance(i, j) << *i;

            i = j;
        }

        return ss.str();
    }

};

int main()
{
    int n = 4;
    Solution_A S;
    string res = S.countAndSay(n);

    cout << "res : " << res << endl;

    return 0;

}

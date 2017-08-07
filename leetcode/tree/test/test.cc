/*
 * Filename   test.cc
 * CreateTime 2017-03-18 23:21:11
 * 
 * Copyright  (C) Zhao Huanzhen
 * Copyright  (C) zhzcsp@gmail.com
 */

#include <iostream>
#include <vector>
using namespace std;


//test

int main()
{
    vector<int> v{1,2,3,4,5,6,7};

    for (int i = 0; i < v.size() - 1; i++) {
        if (v[i] < v[i+1]) {
            cout << ' ' << v[i];
        } else {
            cout << "False!" << endl;
            break;
        }
    }

    cout << endl << "Done!!" << endl;

    return 0;
}

/*
 * Filename   Jump_game.cc
 * CreateTime 2017-04-15 21:26:29
 * 
 * Copyright  (C) Zhao Huanzhen
 * Copyright  (C) zhzcsp@gmail.com
 */

#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool canJump(int A[], int n)
    {
        if (n == 0) return true;
        int leftmost = n - 1;

        for (int i = n - 1; i >= 0; --i) {
            if (i + A[i] >= leftmost) {
                leftmost = i;
            }
        }
        
        return leftmost == 0;
    }
};

int main()
{
    int A[] = {3,2,1,0,4};
    Solution S;
    bool res = S.canJump(A, sizeof(A)/sizeof(int));

    if (res)
        cout << "TRUE!" << endl;
    else
        cout << "FALSE!" << endl;

    return 0;
}

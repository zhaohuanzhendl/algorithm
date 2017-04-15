/*
 * Filename   Jump_game_II.cc
 * CreateTime 2017-04-15 22:28:51
 * 
 * Copyright  (C) Zhao Huanzhen
 * Copyright  (C) zhzcsp@gmail.com
 */

#include <iostream>
using namespace std;

class Solution {
public:
    int jump(int A[], int n)
    {
        if (n <= 1)  return 0;

        int step = 0, left = 0, right = 0;

        while (left <= right) {
            ++step;
            for (int i = left; i < right; i++) {
                int old_right = right;
                new_right = i + A[i];
                if (new_right > n - 1)  return step;
                if (new_right > right) {
                    right = new_right;
                }
            } //end for
            left = old_right + 1;
        
        }//end while

        return 0;
    }
};

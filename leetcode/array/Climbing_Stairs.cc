/*
 * Filename   Climbing_Stairs.cc
 * CreateTime 2019-02-16 22:07:53
 * 
 * Copyright  (C) Zhao Huanzhen
 * Copyright  (C) zhzcsp@gmail.com
 */

#include <iostream>
using namespace std;

/*
 *ret[i] = ret[i-1] + ret[i-2]
 *起始条件：ret[1] = 1, ret[2] = 2
 *事实上由于ret[i]只由前两个结果决定，并不需要储存整个队列。
 *
 */

//S O(1), T O(N)

class Solution {
public:
    int climbStairs(int n) {
        if(n<=0) return 0;
        int p1 = 1, p2 =1;
        for(int i=2; i<=n; i++) {
            int temp = p1+p2;
            p1 = p2;
            p2 = temp;
        }
        return p2;
    }
};


/*
 * Filename   Remove_Duplicates_from_Sorted_Array.cc
 * CreateTime 2019-02-15 21:58:42
 * 
 * Copyright  (C) Zhao Huanzhen
 * Copyright  (C) zhzcsp@gmail.com
 */

#include <iostream>
#include <algorithm>

using namespace std;

/*
 *Given a sorted array, remove the duplicates in place such that each elem
 *appear only once and retun the NEW LENTH!!!
 *
 */

class Solution {
public:
    int rmDup(int A[], int n)
    {
        if (n == 0)  return 0;

        int index = 0;
        for (int i=0; i<n; i++) {
            if (A[index] != A[i]) 
                A[++index] = A[i];
        }

        return index;
    }

};

/*
 *该函数的作用是“去除”容器或者数组中相邻元素的重复出现的元素，注意
 *(1) 这里的去除并非真正意义的erase，而是将重复的元素放到容器的末尾，
 * 返回值是去重之后的尾地址。 
 *(2) unique针对的是相邻元素，所以对于顺序顺序错乱的数组成员，或者容器成员，
 * 需要先进行排序，可以调用std::sort()函数
 */
class Solution_two {
public:
    int rmDup(int A[], int n)
    {
        return distance(A, unique(A, A+n));
    }
};

///////////////////////////////////////////////////////
//Remove Duplicates from Sorted Array II
//What if duplicates are allowed at most twice?
//
class Solution_II {
public:
    int rmDup(int A[], int n)
    {
        if (n<=2) return n;
        
        int index = 2;
        for (int i=0; i<n; i++) {
            if (A[index-2] != A[i])
                A[index++] = A[i];
        }

        return index;
    }
};

//unittest
int main()
{
    int A[10] = {1,1,1,2,2,2,3,3,3,4};
    Solution s;
    cout << "s.rmDup: "<< s.rmDup(A,10) << endl;

    Solution_two s_two;
    cout << "s_two.rmDup: "<< s_two.rmDup(A,10) << endl;

    Solution_II s_II;
    cout << "s_II.rmDup: "<< s_II.rmDup(A,10) << endl;
    return 0;
}

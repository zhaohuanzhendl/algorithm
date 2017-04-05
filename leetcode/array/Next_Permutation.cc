/*
 * Filename   Next_Permutation.cc
 * CreateTime 2017-04-02 07:19:32
 * 
 * Copyright  (C) Zhao Huanzhen
 * Copyright  (C) zhzcsp@gmail.com
 */

#include <iostream>
using namespace std;

//test
//solution 1
template<typename BidirectionalIterator>
bool next_permutation (
        BidirectionalIterator first,
        BidirectionalIterator last
        )
{

    if (first == last)  return false;

    BidirectionalIterator i = first;
    ++i;

    if (i == last) return false; //only 1 elment 

    i = last;
    --i;

    for (; ;) {
        BidirectionalIterator ii = i;
        --i;

        if (*i < *ii) {
            BidirectionalIterator j = last;
            while (!(*i < *(--j))) ;

            iter_swap(i, j);
            reverse(ii, last);
            
            return true;
        }

        if (i == first) {
            reverse(first, last);
            return false;
        }
    }

}

//solution 2
class Solution {
public:
   ; 
};

/*
 * Filename   Next_Permutations.cc
 * CreateTime 2017-03-31 06:59:40
 * 
 * Copyright  (C) Zhao Huanzhen
 * Copyright  (C) zhzcsp@gmail.com
 */

/*
 *REF : http://www.cnblogs.com/devymex/archive/2010/08/17/1801122.html
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution_nextP {
public:
    vector<vector<int> > permute(vector<int> &num)
    {
        vector<vector<int> > result;
        sort(num.begin(), num.end());

        do {
            result.push_back(num);
        } while (next_permutation(num.begin(), num.end()));

        return result;
    }
};



class Solution {
public:
    void nextPermut(vector<int> &num)
    {
        next_permutation(num.begin(), num.end());
    }

    template<typename BidIt>
    bool next_permutation(BidIt first, BidIt last)
    {
        const auto rfirst = reverse_iterator<BidIt>(last);
        const auto rlast = reverse_iterator<BidIt>(first);

        auto pivot = next(rfirst);
        while (pivot != rlast && *pivot >= *prev(pivot)) {
            ++pivot;
        }

        if (pivot == rlast) {
            reverse(rfirst, rlast);
            return false;
        }

        auto change = find_if (rfirst, pivot, bind1st(less<int>(), *pivot));
        swap(*pivot, *change);
        reverse(rfirst, pivot);

        return true;

    }
};


int main()
{
    //vector<int> num = {1,2,3,4,6};
    vector<int> num = {6,8, 4,7,3,2};
    Solution_nextP SL;
    vector<vector<int> > res = SL.permute(num);
    //for_each(res.begin(), res.end(), cout);
    for (auto e : res){
        for (auto es : e) {
            cout << es << ' ';
        }
        cout << endl;
    
    }
    cout << endl;

    return 0;
}

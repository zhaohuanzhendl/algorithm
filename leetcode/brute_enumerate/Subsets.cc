/*
 * Filename   Subsets.cc
 * CreateTime 2017-03-30 19:46:47
 * 
 * Copyright  (C) Zhao Huanzhen
 * Copyright  (C) zhzcsp@gmail.com
 */

/*
 * REF: http://bangbingsyb.blogspot.com/2014/11/leetcode-subsets-i-ii.html
 */

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution_backTrace {
public:
    vector<vector<int> > subsets(vector<int> &S)
    {
        vector<vector<int> > allSets;
        vector<int> sol;
        allSets.push_back(sol);

        sort(S.begin(), S.end());
        findSubsets(S, 0, sol, allSets);

        return allSets; 
    }

    void findSubsets(vector<int> &S, int start, vector<int> &sol, vector<vector<int> > &allSets)
    {
        for (int i  = start; i < S.size(); i++) {
            sol.push_back(S[i]);
            allSets.push_back(sol);
            findSubsets(S, i+1, sol, allSets);
            sol.pop_back();
            //sol.clear(); // Watch!! not clear
        }
    }
};

class Solution_addNum {
public:
    vector<vector<int> > subsets(vector<int> &S)
    {
        vector<int> sol;
        vector<vector<int> > allSets;
        allSets.push_back(sol);
        sort(S.begin(), S.end());
        
        for (int i = 0; i < S.size(); i++) {
            int n = allSets.size();
            for (int j = 0; j < n; j++) {
                sol = allSets[j];
                sol.push_back(S[i]);
                allSets.push_back(sol);
            }
        }

        return allSets;
    }
};


//bit manipulation
class Solution_Bit {
public:
    vector<vector<int> > subsets(vector<int> &S)
    {
        vector<vector<int> > allSets;
        unsigned long long maxNum = pow(2, S.size()) - 1;

        for (unsigned long long i = 0; i <= maxNum; i++) {
            allSets.push_back(sub2sets(S, i));
        }

        return allSets;
    }

    vector<int> sub2sets(vector<int> &S, unsigned long long num)
    {
        vector<int> sol;
        int i = 0;

        while (num) {
            if (num & 1) {
                sol.push_back(S[i]);
            } 

            num >>= 1;
            i++;
        }

        return sol;
    }
};


//unit test
int main()
{
    //Solution_backTrace SL;
    //Solution_addNum SL;
    Solution_Bit SL;

    vector<int> S = {1, 2, 3, 4};
    vector<vector<int> > res = SL.subsets(S);

    /*
    vector<vector<int> > res = { {1},
                                 {2},
                                 {3},
                                 {1, 2},
                                 {1, 2, 3}
                                };
    */

    for (auto e : res) {
        for (auto e_sub : e) {
            cout << e_sub << ' ';
        }
        cout << endl;
    }
    cout << endl;
    
    return 0;
}

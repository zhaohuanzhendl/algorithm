/*
 * Filename   Combination_Sum.cc
 * CreateTime 2017-04-10 03:17:55
 * 
 * Copyright  (C) Zhao Huanzhen
 * Copyright  (C) zhzcsp@gmail.com
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &condidates, int target)
    {
        vector<vector<int> > allSol;
        vector<int> sol;
        if (condidates.empty()) return allSol;
        sort(condidates.begin(), condidates.end());
        dfs(condidates, 0, target, sol, allSol);

        return allSol;
    }

    void dfs(vector<int> &condidates, int start, int target, vector<int> &sol, vector<vector<int> > &allSol)
    {
        if (target == 0) {
            allSol.push_back(sol);
            return;
        }

        for (int i = start; i < condidates.size(); i++) {
            if (condidates[i] <= target) {
                sol.push_back(condidates[i]);
                dfs(condidates, i, target-condidates[i], sol, allSol);
                sol.pop_back();
            }
        
        }
    
    }
};

int main()
{
    vector<int> c{4,3,6};
    int tgt = 6;
    Solution S;
    vector<vector<int> > res = S.combinationSum(c, tgt);

    for (auto v : res) {
        for (auto e : v ) {
            cout<< e << ' ';
        }
        cout << endl;
    }

    cout << endl;

    return 0;

}

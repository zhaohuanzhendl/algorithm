/*
 * Filename   N-Queens.cc
 * CreateTime 2017-04-09 07:10:29
 * 
 * Copyright  (C) Zhao Huanzhen
 * Copyright  (C) zhzcsp@gmail.com
 */

//ref: http://bangbingsyb.blogspot.com/2014/11/leetcode-n-queens-i-ii.html

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<vector<string> > solveNQueesn(int n) {
        vector<vector<string> > allSol;
        vector<string> sol;
        vector<int> col;
        dfs(n, 0, col, sol, allSol);
        
        return allSol;
    }

    void dfs(int n, int irow, vector<int> &col, vector<string> &sol, vector<vector<string> > &allSol) {
        if (irow == n) {
            allSol.push_back(sol);
            return;
        }

        for (int icol = 0; icol < n; icol++) {
            if (validPos(col, irow, icol)) {
                string s(n, '.');
                s[icol] = 'Q';
                sol.push_back(s);
                col.push_back(icol);
                dfs(n, irow+1, col, sol, allSol);
                sol.pop_back();
                col.pop_back();
            }
        }
    }

    bool validPos(vector<int> &col, int irow, int icol) {
        if (irow < col.size()) {
            return false;
        }

        for (int i = 0; i < col.size(); i++) {
            if (icol == col[i] || abs(irow - i) == abs(icol - col[i])) {
                return false;
            }
        }

        return true;
    }
};

int main()
{

    Solution S;
    vector<vector<string> > res = S.solveNQueesn(4);

    for (auto r : res) {
        for (auto v: r) {
            cout << v << endl;
        }
        cout << endl;
    }
    cout << endl;

    return 0;
}

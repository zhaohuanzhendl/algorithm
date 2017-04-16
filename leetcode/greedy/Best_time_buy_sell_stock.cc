/*
 * Filename   Best_time_buy_sell_stock.cc
 * CreateTime 2017-04-15 23:46:41
 * 
 * Copyright  (C) Zhao Huanzhen
 * Copyright  (C) zhzcsp@gmail.com
 */

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution_p1 {
public:
    int maxProfit(vector<int> &prices)
    {
        if (prices.size() < 2) return 0;
        int profit = 0;
        cur_min = prices[0];

        for (int i = 0; i < prices.size(); i++) {
            profit = max(profit, prices[i] - cur_min);
            cur_min = min(cur_min, prices[i]);
        
        }

        return profit;
    }
};

class Solution_p2 {
public:
    int maxProfit_seg(vector<int> &prices)
    {
        int sum = 0;

        for (int i = 0; i < prices.size(); i++) {
            diff = prices[i] - prices[i-1];
            if (diff > 0)  {
                sum += diff;
            }
        }

        return sum;
    }
};

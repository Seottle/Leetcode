#include <stdio.h>
#include <iostream>
using namespace std;

/**
@author: ZhengXiaoTao
@description: 
*/
//对比121 （只能进行一次操作）
/*
121
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0) return 0;
        int minprice = INT_MAX;
        int maxprofit = INT_MIN;
        for(int i = 0; i < prices.size(); ++i) {
            minprice = min(prices[i], minprice);
            maxprofit = max(maxprofit, prices[i] - minprice);
        }
        return maxprofit;
    }
};


*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0) return 0;
        int buy1 = INT_MAX;
        int buy2 = buy1;
        int profit1 = INT_MIN;
        int profit2 = profit1;
        for(int i = 0; i < prices.size(); ++i) {
            buy1 = min(buy1, prices[i]);
            profit1 = max(profit1, prices[i] - buy1);
            //在第二次买的时候，价格其实是考虑用了第一次赚的钱去补贴
            buy2 = min(buy2, prices[i] - profit1);
            profit2 = max(profit2, prices[i] - buy2);
        }
        return profit2;
    }
};
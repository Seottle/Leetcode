#include <stdio.h>
#include <iostream>
using namespace std;

/**
@author: ZhengXiaoTao
@description: 2020.11.4 买卖股票的最佳时机2
*/


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max = 0;
        int len = prices.size();
        for(int i = 0; i < len - 1; ++i) {
            int tmp = (prices[i + 1] - prices[i]);
            if(tmp > 0) {
                max += tmp;
            }
        }
        return max;
    }
};
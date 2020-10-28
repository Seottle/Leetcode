#include <stdio.h>
#include <iostream>
using namespace std;

/**
@author: ZhengXiaoTao
@description:股票买入最佳时机 
*/


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sum = 0, max = 0;
        int len = prices.size();
        for(int i = 0; i < len - 1; ++i) {
            sum += (prices[i + 1] - prices[i]);
            if(sum < 0) {
                sum = 0;
                continue;
            }
            if(sum > max) {
                max = sum;
            }
        }
        return max;
    }
};
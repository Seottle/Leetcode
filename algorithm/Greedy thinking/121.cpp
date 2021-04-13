#include <stdio.h>
#include <iostream>
using namespace std;

/**
@author: ZhengXiaoTao
@description: 2020.11.1买卖股票的时机1
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max = 0, temp = 0;
         int len = prices.size();
        for(int i = 0; i < len - 1; ++i) {
            temp += (prices[i + 1] - prices[i]);
            
            if(temp > max)
                max = temp;

            if(temp < 0) {
                temp = 0;
            }
        }
        return max;
    }
};
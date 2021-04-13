#include <stdio.h>
#include <iostream>
using namespace std;

/**
@author: ZhengXiaoTao
@description: 
*/


class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if(n == 0) return 0;
        if(k >= n / 2) { //近似等于无限次交易
            int sum = 0;
            int low = prices[0];
            for(int i = 1; i < prices.size(); ++i) {
                if(prices[i] > low) {
                    sum += (prices[i] - low);
                    low = prices[i];
                }
                else {
                    low = prices[i];
                }
            }
            return sum;
        }
        int dp[k + 1][2];
         for(int i=0; i<=k; ++i) {
            dp[i][0] = 0;//第i次交易 不持股
            dp[i][1] = -prices[0]; //第i次交易 持股
        }
        for(int i = 1; i < prices.size(); ++i) {
            for(int j = k; j > 0; --j) {  //逆序去掉重复项
                dp[j][0] = max(dp[j][0], dp[j - 1][1] + prices[i]);//不持股

                dp[j - 1][1] = max(dp[j - 1][1], dp[j - 1][0] - prices[i]);//持股
            }
        }
        return dp[k][0];
    }
};
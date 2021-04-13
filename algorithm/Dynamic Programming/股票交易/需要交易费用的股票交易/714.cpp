#include <stdio.h>
#include <iostream>
using namespace std;

/**
@author: ZhengXiaoTao
@description: 2020 12 3
*/
//对比122题（尽可能多的操作）， 122题是  把每次(峰 - 谷)求和即可
//此题是  把每次  (峰-fee) - 谷 求和即可  需要判断   (峰 - fee)  > 谷
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        if(prices.size() == 0) return 0;
        int sum = 0;
        int low = prices[0];
        for(int i = 1; i < prices.size(); ++i) {
            if(prices[i] < low) {
                low = prices[i];
            }
            else if(prices[i] - fee > low) {
                sum += (prices[i] - fee - low);
                low = prices[i] - fee;
            }
        }
        return sum;
    }
};
//dp
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        if(prices.size() < 2) return 0;
        int dp[prices.size()][2];
        //初始化
        //1.不持股状态下的最大收益2.持股状态下的最大收益
        dp[0][0] = 0;//初始时不持股，收益为0
        dp[0][1] = -1 * prices[0]; //初始时持股没卖出，收益为买入的价格
        
        for(int i = 1; i < prices.size(); ++i) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i] - fee);//不持股状态由两种维护：1.上一次也不持股2.上一次持股，这次卖出
            dp[i][1] = max(dp[i - 1][0] - prices[i], dp[i - 1][1]);//持股状态由1.上一次不持股这次买入2.上一次持股，这次不操作
        }
        return dp[prices.size() - 1][0];
    }
};
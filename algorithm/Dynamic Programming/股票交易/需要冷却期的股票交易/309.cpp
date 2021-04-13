#include <stdio.h>
#include <iostream>
using namespace std;

/**
@author: ZhengXiaoTao
@description: 
*/

class Solution {
public:

    int maxProfit(vector<int>& prices) {
        //需要冷冻期的买入股票问题有三个要点
        int dp[prices.size()][3];
        //1.不持股且没卖出dp[i][0]
        //2.持股且买入dp[i][1]
        //3.不持股且卖出dp[i][2]
        //初始化
        dp[0][0] = 0;//第0天不持股且没有卖出，收益为0
        dp[0][1] = -1 * prices[0];//第0天持股买入，收益为买股花了的钱
        dp[0][2] = 0;//因为第0天不持股意味着也不存在卖出，所以收益为0

        for(int i = 1; i < prices.size(); ++i) {
            //情况1的dp[i][0]的最大值分为前一天不持股且不卖出的最大值和前一天卖出了,今天是冷冻期
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][2]);
            //情况2的dp[i][1]的最大值分为前一天持股买入和 前一天不持股不卖出，今天买入的 最大值
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
            //情况3的dp[i][2]的最大值就是前一天持股且今天卖出！前一天持股才能让今天是不持股且卖出的状态
            dp[i][2] = dp[i - 1][1] + prices[i];
        }  

        return max(dp[prices.size() - 1][0], dp[prices.size() - 1][2]);
    }
};
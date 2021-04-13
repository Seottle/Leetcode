#include <stdio.h>
#include <iostream>
using namespace std;

/**
@author: ZhengXiaoTao
@description: 2020 11 30 零钱兑换
完全背包问题！！！
关键信息:物品可重复使用，将内部循环改成顺序
*/


//dp

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0 || coins.size() == 0) return 0;
        int dp[amount + 1];
        memset(dp, 0, sizeof(dp));
        for (int j = 0; j < coins.size(); ++j) {
            for (int i = coins[j]; i <= amount; i++) { //将逆序遍历改为正序遍历
                if (i == coins[j]) {
                    dp[i] = 1;
                } else if (dp[i] == 0 && dp[i - coins[j]] != 0) {
                    dp[i] = dp[i - coins[j]] + 1;

                } else if (dp[i - coins[j]] != 0) {
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }
        if(dp[amount] != 0) return dp[amount];
        else return -1;
    }
};
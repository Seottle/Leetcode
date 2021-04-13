#include <stdio.h>
#include <iostream>
using namespace std;

/**
@author: ZhengXiaoTao
@description: 2020 11 21 爬楼梯
*/


class Solution {
public:
    int climbStairs(int n) {
        int dp[10010];
        dp[1] = 1;
        dp[2] = 2;
        for(int i = 3; i <= n; ++i) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};
#include <stdio.h>
#include <iostream>
using namespace std;

/**
@author: ZhengXiaoTao
@description: 
*/


class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> dp(num + 1);
        dp[0] = 0;
        for(int i = 1; i <= num; ++i) {
            dp[i] = dp[i&(i - 1)] + 1;
        }
        return dp;
    }
};
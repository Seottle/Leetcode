#include <stdio.h>
#include <iostream>
using namespace std;

/**
@author: ZhengXiaoTao
@description: 2020 11 21 打家劫舍
*/


class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.empty()) {
            return 0;
        }
        int n = nums.size();
        if (n == 1) {
            return nums[0];
        }
        int dp[100010];
        dp[0] = nums[0];
        dp[1] = max(nums[1], dp[0]);
        for(int i = 2; i < n; ++i) {
            dp[i] = max(dp[i - 1],  nums[i] + dp[i - 2]);
        }
        return dp[n - 1];
    }
};
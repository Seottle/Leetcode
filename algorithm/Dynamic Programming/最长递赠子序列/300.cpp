#include <stdio.h>
#include <iostream>
using namespace std;

/**
@author: ZhengXiaoTao
@description: 2020 11 24 最长上升子序列
*/


class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return 1;
        vector<int> dp(nums.size() + 10, 0);
        dp[0] = 0;
        int ans = INT_MIN;
        for(int i = 1; i < nums.size(); ++i) {
            for(int j = 0; j < i; ++j) {
                if(nums[i] <= nums[j]) continue;
                dp[i] = max(dp[j] + 1, dp[i]);
                
            }
            if(dp[i] > ans) {
                ans = dp[i];
            }
        }
        return ans + 1;
    }
};



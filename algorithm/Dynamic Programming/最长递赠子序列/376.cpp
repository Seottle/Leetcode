#include <stdio.h>
#include <iostream>
using namespace std;

/**
@author: ZhengXiaoTao
@description: 2020 11 25 摆动序列
*/


class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        vector<int> dp(nums.size() + 10, 0);
        dp[0] = 1;
        bool flag;
        bool first = true;
        for(int i = 1; i < nums.size(); ++i) {
            if(nums[i] == nums[i - 1]) {
                dp[i] = dp[i - 1];
                continue;
            }
            if(first) {
                if(nums[i] - nums[i - 1] < 0) flag = false;
                else flag = true;
                first = false;
            }
            if(nums[i] - nums[i - 1] > 0 && flag) {
                dp[i] = max(dp[i - 1] + 1, dp[i]);
                flag = !flag;
            }
            else if(nums[i] - nums[i - 1] < 0 && !flag) {
                dp[i] = max(dp[i - 1] + 1, dp[i]);
                flag = !flag;
            }
            else 
                dp[i] = dp[i - 1];
        }
        return dp[nums.size() - 1];
    }
};
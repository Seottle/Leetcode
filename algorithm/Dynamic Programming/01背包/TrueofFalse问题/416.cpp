#include <stdio.h>
#include <iostream>
using namespace std;

/**
@author: ZhengXiaoTao
@description: 2020 11 26 分割等和子集
*/


class Solution {
public:
    bool canPartition(vector<int>& nums) {
        if(nums.size() < 2) return false; // 长度小于2，直接滚
        int sum = 0, MAX = INT_MIN;
        for(int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            MAX = max(nums[i], MAX);
        }
            
        if(sum % 2 == 1) return false;
        int target = sum / 2;

        if(MAX > target) return false;

        vector<vector<int>> dp(nums.size(), vector<int>(target + 1, 0));

        //容量为0时
        for(int i = 0; i < nums.size(); ++i)
            dp[i][0] = true;
        //只有一件物品时
        dp[0][nums[0]] = true;
        for(int i = 1; i < nums.size(); ++i) {
            for(int j = 0; j <= target; ++j) {
                //dp[i][j] = dp[i - 1][j]; 
                if(nums[i] < j) {
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i]];
                }
                else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[nums.size() - 1][target];
    } 
};
#include <stdio.h>
#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

/**
@author: ZhengXiaoTao
@description: 打家劫舍
状态转移方程：dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
状态边界： dp[0] = nums[0];
            dp[1] = max(nums[0], nums[1]);
*/


class Solution {
public:
    int rob(vector<int>& nums) {
        int max = 0;
        int len = nums.size();
        if(len == 1) return nums[0];
        else if(len == 2) {
            int max = nums[0];
            if(max < nums[1]) max = nums[1];
            return max;
        }
        else {
            vector<int> dp = vector<int>(size);
            dp[0] = nums[0];
            dp[1] = max(nums[0], nums[1]);
            for(int i = 2; i < len; ++i) {
               dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);     
            }
        }
            
        return dp[n];
    }
};
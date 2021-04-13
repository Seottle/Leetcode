#include <stdio.h>
#include <iostream>
using namespace std;

/**
@author: ZhengXiaoTao
@description: 2020 11 21 打家劫舍 II
把环拆成0 -- n-1  和 1 -- n 
*/


class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.empty()) {
            return 0;
        }
        int n = nums.size();
        if(n == 1) {
            return nums[0];
        }
        if(n == 2) {
            return max(nums[0], nums[1]);
        }
        int flag = true;
        int dp[10010];
        //偷第一个房子
        dp[0] = nums[0];
        dp[1] = max(nums[1], dp[0]);
        for(int i = 2; i < nums.size() - 1 ; ++i) {
            dp[i] = max(dp[i - 1], nums[i] + dp[i - 2]);      
        }
        //不偷第一个房子
        int dp2[10010];
        dp2[1] = nums[1];
        dp2[2] = max(nums[2], dp2[1]);
        for(int i = 3; i < nums.size(); ++i) {
            dp2[i] = max(dp2[i - 1], nums[i] + dp2[i - 2]);
        } 
        int ans = max(dp[nums.size() - 2], dp2[nums.size() - 1]);
        return ans;
    }
};
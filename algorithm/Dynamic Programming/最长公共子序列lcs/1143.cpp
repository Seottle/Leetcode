#include <stdio.h>
#include <iostream>
using namespace std;

/**
@author: ZhengXiaoTao
@description: 2020 11 26 最长公共子序列lcs
对于两个字符串str1 str2求最长公共子序列的问题，基本套路都是用一个dp[str1.length + 1][str2.length + 1]的dp数组用来存储答案
(我们用dp[0][--] 和 dp[--][0] 表示 str1 = "" , str2 非空的情况，此时lcs都是0)
每次结果dp[i][j] 的最优解都来自dp[i - 1][j] ，dp[i][j - 1]; 

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
        for(int i = 0; i < n; ++i)
            dp[i][0] = true;
        //只有一件物品时
        dp[0][nums[i]] = true;
        for(int i = 1; i < nums.size(); ++i) {
            for(int j = 0; j <= target; ++j) {
                
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
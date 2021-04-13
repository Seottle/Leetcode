#include <stdio.h>
#include <iostream>
using namespace std;

/**
@author: ZhengXiaoTao
@description: 12 2  组合总和 Ⅳ
*/

//dfs 超时
class Solution {
public:
    int cnt = 0;
    void dfs(vector<int>& nums, int target) {
        if(target == 0) {
            cnt++;
            return;
        }
        for(int i = 0; i < nums.size(); ++i) {
            if(nums[i] <= target) {
                dfs(nums, target - nums[i]);
            }
        }
    }
    int combinationSum4(vector<int>& nums, int target) {
        if(nums.size() == 0) return 0;
        dfs(nums, target);
        return cnt;
    } 
};
//
class Solution {
public:
    //完全背包
    int combinationSum4(vector<int>& nums, int target) {
        if(nums.size() == 0) return 0;
        vector<unsigned long long> dp(target + 1, 0);
        //ull的范围是[0,2^64-1]。
        //ll的范围是[-2^63,2^63-1]，因为有符号的第63位表示“正负”而不表示数值
        dp[0] = 1;
        for(int i = 1; i < target+1; ++i) {
            for(int j = 0; j < nums.size(); ++j) {
                if(i >= nums[j]) {
                    dp[i] += dp[i - nums[j]];
                }
            }
        }
        return dp[target];
    }
};
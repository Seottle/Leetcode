#include <stdio.h>
#include <iostream>
using namespace std;

/**
@author: ZhengXiaoTao
@description: 2020 11 27    目标和   
0-1背包问题
*/


class Solution {
public:
    int cnt = 0;
    void dfs(vector<int>& nums, int S, int sum, int index) {
        if(index == nums.size()) {
            if(sum == S) {
                cnt++;
            }
            //return;
        }
        else {
            dfs(nums, S, sum - nums[index], index + 1);
            dfs(nums, S, sum + nums[index], index + 1);
        }
        
    }
    int findTargetSumWays(vector<int>& nums, int S) {
        if(nums.size() == 0) return 0;
        int sum = 0;
        dfs(nums, S, sum, 0);
        return cnt;
    }   

};
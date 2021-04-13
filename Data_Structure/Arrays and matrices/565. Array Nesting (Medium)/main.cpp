#include <stdio.h>
#include <iostream>
using namespace std;

/**
@author: ZhengXiaoTao
@description: 
*/


class Solution {
public:
    void dfs(vector<int>& nums, int i, vector<int>& memo, int &cnt) {
        if(memo[nums[i]] == 1) return;
        memo[nums[i]] = 1;
        cnt++;
        dfs(nums, nums[i], memo, cnt);
    }
    int arrayNesting(vector<int>& nums) {
        vector<int> memo(nums.size() + 10, 0);
        int ret = 0;
        for(int i = 0; i < nums.size(); ++i) {
            int cnt = 0;
            dfs(nums, i, memo, cnt);
            ret = max(ret, cnt);
        }
        return ret;
    }
};
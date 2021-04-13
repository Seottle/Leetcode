#include <stdio.h>
#include <iostream>
using namespace std;

/**
@author: ZhengXiaoTao
@description: 2020 11 17 全排列 II
*/


class Solution {
public:
    void dfs(vector<vector<int>>& ans, vector<int> tmp, vector<int> nums, vector<int> visit) {
        if(tmp.size() == nums.size()) {
            ans.push_back(tmp);
            return;
        }
        for(int i = 0; i < nums.size(); ++i) { //i从0开始
            if(visit[i] == 1 || (i > 0 && nums[i - 1] == nums[i] && visit[i - 1] == 1)) {
                //(i > 0 && nums[i - 1] == nums[i] && visit[i - 1] == 1)
                //从i > 0 开始，如果有相邻的数字，要判断他之前的那个数字是否被访问过，被访问过就跳过
                continue;
            }
            visit[i] = 1;
            tmp.push_back(nums[i]);
            dfs(ans, tmp, nums, visit);
            tmp.pop_back();
            visit[i] = 0;
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        if(nums.size() == 0) return ans;
        sort(nums.begin(), nums.end());   //保证相同的数字相邻
        vector<int> visit(nums.size(), 0);
        vector<int> tmp;
        dfs(ans, tmp, nums, visit);
        return ans;
    }
};
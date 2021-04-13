#include <stdio.h>
#include <iostream>
using namespace std;

/**
@author: ZhengXiaoTao
@description: 2020 11 19 子集
*/


class Solution {
public:
    void dfs(vector<vector<int>>& ans, vector<int> temp, vector<int>& nums, int index) {
        for(int i = index; i < nums.size(); ++i) {
            if(i > 0 && nums[i] == nums[i - 1]) continue;
            temp.push_back(nums[i]);
            dfs(ans, temp, nums, i + 1);
            if(!temp.empty()) {
                ans.push_back(temp);
            }
            temp.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        if(nums.size() == 0) return ans;
        vector<int> temp;
        dfs(ans, temp, nums, 0);
        ans.push_back({});
        return ans;
    }
};
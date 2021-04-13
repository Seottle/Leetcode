#include <stdio.h>
#include <iostream>
using namespace std;

/**
@author: ZhengXiaoTao
@description:2020 11 16   Permutations (Medium) 
*/


class Solution {
public:
    void dfs(vector<vector<int>>& ans, vector<int>& nums, vector<int> tmp, vector<int> visit) {
        if(tmp.size() == nums.size()) {
            ans.push_back(tmp);
            return;
        }
        for(int i = 0; i < nums.size(); ++i) { //i 从 0 开始
            if(visit[i] == 0) {
                visit[i] = 1;
                tmp.push_back(nums[i]);
                dfs(ans, nums, tmp, visit);
                tmp.pop_back();     //少了这部，去掉最后一个元素!很关键!!
                visit[i] = 0;
            }
            else continue;
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        if(nums.size() == 0) return ans;
        vector<int> tmp;
        vector<int> visit;
        visit.resize(nums.size());
        dfs(ans, nums, tmp, visit);
        return ans;
    }
};
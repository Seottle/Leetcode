#include <stdio.h>
#include <iostream>
using namespace std;

/**
@author: ZhengXiaoTao
@description: 2020 11 18 组合求和二

*/

class Solution {
public:
    void dfs(vector<vector<int>>& ans,vector<int>& candidates, vector<int> temp, int target, int index) {
        if(target == 0) {
            ans.push_back(temp);
            return;
        }
        for(int i = index; i < candidates.size(); ++i) {
            if(i > index && candidates[i] == candidates[i - 1] ) continue;
            if(candidates[i] <= target) {
            temp.push_back(candidates[i]);
            dfs(ans, candidates, temp, target - candidates[i], i + 1);
            temp.pop_back();

            }
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        if(candidates.size() == 0) return ans;
        sort(candidates.begin(), candidates.end());
        vector<int> visit(candidates.size(), 0);
        vector<int> temp;
        dfs(ans, candidates,  temp, target, 0);
        return ans;
    }
};
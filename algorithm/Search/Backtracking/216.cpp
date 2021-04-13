#include <stdio.h>
#include <iostream>
using namespace std;

/**
@author: ZhengXiaoTao
@description: 2020 11 19 组合总和 III

*/


class Solution {
public:
    void dfs(vector<vector<int>>& ans, vector<int> temp, int k, int n, int index) {
        if(temp.size() == k && n == 0) {
            ans.push_back(temp);
            return;
        }
        for(int i = index; i < 10; ++i) {
            if(i <= n) {
                temp.push_back(i);
                dfs(ans, temp, k, n - i, i + 1);
                temp.pop_back();
            }
        }
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        if(n == 0 || k == 0) return ans;
        vector<int> temp;
        dfs(ans, temp, k, n, 1);
        return ans;
    }
};
#include <stdio.h>
#include <iostream>
using namespace std;

/**
@author: ZhengXiaoTao
@description: 2020 11 16 组合

*/


class Solution {
public:  
    vector<vector<int>> ans;
    void dfs(vector<int>& tmp, int n, int k, int x) {
        if(tmp.size() == k) {
            ans.push_back(tmp);
            return;
        }
        for(int i = x; i <= n; ++i) { // i 从x开始
            tmp.push_back(i);
            dfs(tmp, n, k, i + 1);
            tmp.pop_back();         //关键！
        }
    }   
    vector<vector<int>> combine(int n, int k) {
        vector<int> tmp;
        dfs(tmp, n, k, 1);
        return ans;
    }   
};
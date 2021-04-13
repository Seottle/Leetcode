#include <stdio.h>
#include <iostream>
using namespace std;

/**
@author: ZhengXiaoTao
@description: 
*/


class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        if(nums.size() * nums[0].size() != r * c) return nums;
        //nums.size()是行， nums[0].size()是列
        int col = nums[0].size();
        vector<vector<int>> ans(r, vector<int>(c));
        int index = 0;
        for(int i = 0; i < r; ++i) {
            for(int j = 0; j < c; ++j) {
                ans[i][j] = nums[index / col][index % col];
                index++;
            }
        }
        return ans;
    }
};
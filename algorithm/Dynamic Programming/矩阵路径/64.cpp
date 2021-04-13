#include <stdio.h>
#include <iostream>
using namespace std;

/**
@author: ZhengXiaoTao
@description: 2020 11 21  最小路径和

忘了考虑 //考虑row = 0, col的情况 
        //考虑col = 0, row 的情况
*/


class Solution {
public:

    int minPathSum(vector<vector<int>>& grid) {
        if(grid.size() == 0 || grid[0].size() == 0) return 0;
        int row = grid.size();
        int col = grid[0].size();
        
        vector<vector<int>> dp(row, vector<int>(col));
        dp[0][0] = grid[0][0];

        //考虑row = 0, col的情况
        for(int j = 1; j < col; ++j) {
            dp[0][j] = dp[0][j - 1] + grid[0][j];
        }
        //考虑col = 0, row 的情况
        for(int i = 1; i < row; ++i) {
            dp[i][0] = dp[i - 1][0] + grid[i][0];
        }
        // 当 row > 0 && col > 0
        for(int i = 1; i < row; ++i) {
            for(int j = 1; j < col; ++j) {
                dp[i][j] = grid[i][j] + min(dp[i][j - 1], dp[i - 1][j]);  
            }
        }
        return dp[row - 1][col - 1];
    }
};
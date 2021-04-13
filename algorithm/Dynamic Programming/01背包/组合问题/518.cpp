#include <stdio.h>
#include <iostream>
using namespace std;

/**
@author: ZhengXiaoTao
@description: 
*/

//dfs超时
class Solution {
public:
    int cnt = 0;
    void dfs(int amount, vector<int>& coins, int index) {
        if(amount == 0) {
            cnt++;
            return;
        }
        for(int i = index; i < coins.size(); ++i) {
            if(coins[i] <= amount) {
                dfs(amount - coins[i], coins, i);
            }
        }
    }
    int change(int amount, vector<int>& coins) {
        if(amount == 0 && coins.size() == 0) return 1;
        if(amount == 1 && coins.size() == 0) return 0;
        dfs(amount, coins, 0);
        return cnt;
    }
};
//dp
class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        if(n * m == 0) return 0;
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        dp[0][0] = grid[0][0];
        //if col = 0
        for(int i = 1; i < n; ++i) {
            dp[i][0] = dp[i - 1][0] + grid[i][0];
        }
        // if row = 0
        for(int i = 1; i < m; ++i) {
            dp[0][i] = dp[0][i - 1] + grid[0][i];
        }
        // if row && col > 0
        for(int i = 1; i < n; ++i) {
            for(int j = 1; j < m; ++j) {
                dp[i][j] = grid[i][j] + max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[n - 1][m - 1];
    }
};
#include <stdio.h>
#include <iostream>
using namespace std;

/**
@author: ZhengXiaoTao
@description: 2020 11 30 一和零
多维 0 1 背包问题
*/

class Solution {
public:
    //此题思路是：多维01背包问题，dp[i][j]分别是代表是否有 前i个0和前j个1的 容量的最大值
    //解题小细节，算出字符串数组中的每一个子集的01的个数，然后每一次都执行对容量为m和n的01个数求最大dp
    int findMaxForm(vector<string>& strs, int m, int n) {
        int dp[m + 1][n + 1] ;
        memset(dp, 0, sizeof(dp));
        for(int i = 0; i < strs.size(); ++i) {
            int temp[2];
            memset(temp, 0, sizeof(temp));
            for(int l = 0; l < strs[i].size(); ++l) {
                temp[strs[i][l] - '0']++;
            }
            //顺序遍历0的完全背包和1的完全背包
            for(int j = m; j >= 0; --j) {
                for(int k = n; k >= 0; --k) {
                    if(temp[0] > j || temp[1] > k) {
                        dp[j][k] = dp[j][k];
                    }
                    else {
                        dp[j][k] = max(dp[j][k], dp[j - temp[0]][k - temp[1]] + 1);
                    }
                }
            }
        }
        return dp[m][n];
    }
    
};
#include <stdio.h>
#include <iostream>
using namespace std;

/**
@author: ZhengXiaoTao
@description: 
近似为求 最长公共子序列 的题
如果两个字符串完全不匹配（也就是两个字符串没有任何一个字符相同），那么总删除次数是 m + n
。如果两个字符串存在一个公共子序列，长度为 lcs，
两个字符串我们都可以减少 lcs 次删除操作，
也就是总共减少 2 * lcs次删除操作，也就得到了上述等式。
*/


class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        int dp[n + 1][m + 1];
        memset(dp, 0, sizeof(dp)); //全部初始化!!
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= m; ++j) {
                if(word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return n + m - 2 * dp[n][m];
    }
};
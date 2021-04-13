#include <stdio.h>
#include <iostream>
using namespace std;

/**
@author: ZhengXiaoTao
@description: 编辑距离
编辑距离算法被数据科学家广泛应用，是用作机器翻译和语音识别评价标准的基本算法。

最直观的方法是暴力检查所有可能的编辑方法，取最短的一个。所有可能的编辑方法达到指数级，
但我们不需要进行这么多计算，因为我们只需要找到距离最短的序列而不是所有可能的序列。
*/


class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        if(n == 0 && m == 0) return 0;
        int dp[n + 1][m + 1];
        //如果word1为空,word2不为空，则word1变成word2只需要逐个插入即可
        for(int i = 0; i <= m; ++i) {
            dp[0][i] = i;
        }
        //反之同理
        for(int i = 0; i <= n; ++i) {
            dp[i][0] = i;
        }
        //均不为空
        //最小值有3种情况dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= m; ++j) {
                if(word1[i - 1] == word2[j - 1]) {//记住啊！是前一个相等!!!
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else {
                    dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
                }
            }
        }
        return dp[n][m];
    }
};
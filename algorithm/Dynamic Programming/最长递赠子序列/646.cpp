#include <stdio.h>
#include <iostream>
using namespace std;

/**
@author: ZhengXiaoTao
@description: 2020 11 25 最长数对链
*/


class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        vector<int> dp(1010, 1);
        sort(pairs.begin(), pairs.end());
        for(int i = 1; i < pairs.size(); ++i) {
            for(int j = 0; j < i; ++j) {
               if(pairs[i][0] > pairs[j][1]) {
                    dp[i] = max(dp[j] + 1, dp[i]);
                } 
            } 
        }
        return dp[pairs.size() - 1];
    }
};
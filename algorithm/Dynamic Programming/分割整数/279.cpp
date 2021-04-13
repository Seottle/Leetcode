#include <stdio.h>
#include <iostream>
using namespace std;

/**
@author: ZhengXiaoTao
@description: 
*/


class Solution {
public:
    vector<int> square(int n) {
        vector<int> square1;
        int k = sqrt(n);
        for(int i = 1; i <= k; ++i) {
            square1.push_back(i * i);
        }
        return square1;
    }

    int numSquares(int n) {
        vector<int> squa;
        squa = square(n);
        vector<int> dp(n + 1, 0);
        dp[0] = 0;
        for(int i = 1; i <= n; ++i) {
            dp[i] = i; // 每个数最坏的 完全平方数和 的情况就是其本身 
            for(int j = 0; j < squa.size(); ++j) {
                if(i >= squa[j])
                    dp[i] = min(dp[i], dp[i - squa[j]] + 1); 
                //转移方程意思是：N = A*A + B, B = C*C + D,即N的最优解是 A*A（1） + B的最优解，以此类推
            }
        }
        return dp[n];
    }
};
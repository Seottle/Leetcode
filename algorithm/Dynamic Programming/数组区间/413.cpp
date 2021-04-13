#include <stdio.h>
#include <iostream>
using namespace std;

/**
@author: ZhengXiaoTao
@description: 2020 11 22 等差数列划分

终极思路：dp[i] 表示以 A[i] 为结尾的等差递增子区间的个数。
*/


class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int ans = 0;
        if(A.size() == 0) {
            return ans;
        }
        int n = A.size();
        vector<int> dp(n, 0);

        for(int i = 2; i < n; ++i) {
            if(A[i] - A[i - 1] == A[i - 1] - A[i - 2]) {
                dp[i] = dp[i - 1] + 1;
            }
            ans += dp[i];
        }
        return ans;
    }
};
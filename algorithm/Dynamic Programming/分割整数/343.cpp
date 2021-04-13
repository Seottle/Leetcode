#include <stdio.h>
#include <iostream>
using namespace std;

/**
@author: ZhengXiaoTao
@description: 2020 11 23 整数拆分
用动规我不知道一个数怎么拆成其他整数的和

解题思路：
创建dp数组，用dp[i] 存储 数字i拆分成至少两个数的最大乘积，其中 i = 0和 1 时， 都是不可拆分的，最大乘积为 0;

考虑i >= 2时， 假设j 是 i拆分出来的第一个整数，则有
1. 拆分出数字 j 和 i - j ,若此时 i - j 能继续拆分， 则此时 i 的最大拆分乘积为  j * dp[i - j]
2  若不能继续拆分 , 则此时 i 的最大乘积为 j * (i - j)

所以, 考虑此题， 数字i 有 j 从(1 到 i - 1) 个数字拆分情况，故状态转移方程为， 

dp[i] = max( max(j * dp[i - j], j * (i - j)) )
        1<j<i

*/

class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n + 1);
        for(int i = 2; i <= n; ++i) {
            int ans = INT_MIN;
            for(int j = 1; j < i; ++j) {
                ans = max(ans, max(dp[i - j] * j, (i - j) * j));
            }
            dp[i] = ans;
        }
        return dp[n];
    }
};

//dfs超时
class Solution {
public:
    
    void dfs(vector<int> temp, int n, int& max, int k) {
        if(n == 0) {
            int sum = 1;
            for(int i = 0; i < temp.size(); ++i) {
                if(temp[i] != 0)
                    sum *= temp[i];
            }
            if(sum > max) {
                max = sum;
            }
            return;
        }
        for(int i = 1; i < k; ++i) {
            if(i <= n) {
                temp.push_back(i);
                dfs(temp, n - i, max, k);
                temp.pop_back();
            }          
        }
    }
    
    int integerBreak(int n) {
        int max = INT_MIN;
        vector<int> temp(n);
        dfs(temp, n, max, n);
        return max;
    }
};
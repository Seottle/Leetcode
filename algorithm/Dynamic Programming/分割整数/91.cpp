#include <stdio.h>
#include <iostream>
using namespace std;

/**
@author: ZhengXiaoTao
@description: 2020 11 24 解码方法
大佬见解：
这道题目实际上是用DP去做，仔细想的话，可以发现就是约束版的f(n) = f(n-1) + f(n-2);，
其中如果是s[n-1]为0，f(n-1) = 0，f(n) = f(n-2)，因为0无法单独解码，而f(n-2)的条件则是必须在1与26之间，否则f(n) = f(n-1)。
*/

class Solution {
public:
    int numDecodings(string s) {
        if(s[0] == 0 || s.size() == 0) return 0;
        vector<int> dp(s.size() + 10, 0);
        dp[0] = 1;
        for(int i = 0; i < s.size(); ++i) {
            dp[i + 1] = s[i] == '0' ? 0 : dp[i];
            if(i > 0 && (s[i - 1] == '1' ||(s[i - 1] == '2' && s[i] <= '6'))) {
                dp[i + 2] = dp[i];
            dp[i + 1] = dp[i + 1] + dp[i - 1];
            }
        }
        return dp[s.size()];
    }
};
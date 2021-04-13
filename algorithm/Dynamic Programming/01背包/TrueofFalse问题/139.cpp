#include <stdio.h>
#include <iostream>
using namespace std;

/**
@author: ZhengXiaoTao
@description: 2020 12 2  Word Break
完全背包问题
*/


class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        if(s.size() == 0 || wordDict.size() == 0 ) return 0;
        int n = s.size();
        set<string> myset;
        for (string word: wordDict) {
            myset.insert(word);
        }
        vector<bool> dp(n + 1);
        dp[0] = true;
        for(int i = 1; i <= n; ++i) {
            for(int j = 0; j < i; ++j) {
                if(dp[j] && myset.find(s.substr(j, i - j)) != myset.end()) {
                    dp[i] = true;
                }
            }
        }
        return dp[n];
    }
};

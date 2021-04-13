#include <stdio.h>
#include <iostream>
using namespace std;

/**
@author: ZhengXiaoTao
@description: 2020.11.10 单词接龙
此题解法超时 运气好能不超时
*/

class Solution {
public:
    bool CanChange(string a, string b) {
        int diffWord = 0;
        for(int i = 0; i < a.size(); ++i) {
            if(a[i] != b[i]) {
                diffWord++;
            }
            if(diffWord > 1) return false;
        }
        return true;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<string> Q;
        vector<int> memo(wordList.size() + 1, 0);
        Q.push(beginWord);
        int ans = 1;
        while(!Q.empty()) {
            int size = Q.size();
            ans++;
            for(int i = 0; i < size; ++i) {
                string str = Q.front();
                Q.pop();
                for(int j = 0; j < wordList.size(); ++j) {
                    
                    if(memo[j] == 1) continue;
                    if(CanChange(str, wordList[j])) {
                        if(wordList[j] == endWord) return ans;    
                        memo[j] = 1;
                        Q.push(wordList[j]);
                    }
                }
            }
        }    
        return 0;
    }
};
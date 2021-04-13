#include <stdio.h>
#include <iostream>
using namespace std;

/**
@author: ZhengXiaoTao
@description: 2020 11 10 完全平方数
找到完全平方数的组合！也即用target减去那些完全平方数，再去判断差值是不是完全平方数
*/


class Solution {
public:
    vector<int> Getsquares(int n) {
        vector<int> ans;
        for(int i = 1; i <= sqrt(n); ++i) {
            ans.push_back(i * i);
        }
        return ans;
    }
    
    int numSquares(int n) {
       vector<int> square = Getsquares(n);
       
       queue<int> Q;
       vector<int> memo(n + 1, 0); // 从1开始的，要遍历到n，数组长度要为n + 1

        Q.push(n);
        memo[n] = 1;
        int level = 0;
        while(!Q.empty()) {
            int size = Q.size();
            level++;
            for(int i = 0; i < size; ++i) {
                int cur = Q.front(); 
                Q.pop();
                for(int j = 0; j < square.size(); ++j) {
                    int next = cur - square[j];

                    if(next < 0) break;
                    if(next == 0) return level; // 有完全平方数的组合
                    if(memo[next] == 1) continue;

                    memo[next] = 1;
                    Q.push(next);
                }
            }
        }
        return level;
    }
};
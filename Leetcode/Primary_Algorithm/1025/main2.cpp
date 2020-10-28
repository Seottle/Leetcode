#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

/**
@author: ZhengXiaoTao
@description: 计数质数
*/

class Solution {
public:
    int countPrimes(int n) {
        if(n == 0 || n == 1) return 0;
        int prime[n], p[n];
        memset(p,0,sizeof(p));
        int pnum = 0;
        for(int i = 2; i < n; ++i) {
        if(p[i] == 0) {
            prime[pnum++] = 1;
            p[i] = 1;
            for(int j = i + i; j < n; j += i) {
                p[j] = 1;
            }
        }
        }
        int cnt = 0;
        for(int i = 0; i < pnum; ++i) {
            if(prime[i] == 1) cnt++;
        }
        return cnt;
    }
};
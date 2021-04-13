
#include <stdio.h>
#include <iostream>
using namespace std;

/**
@author: ZhengXiaoTao
@description: 只有两个键的键盘
1.素数筛法
2.质因数分解
*/


class Solution {
public:
   //素数就是本身
    int number[1010];
    int prime[1010], pnum = 0;
    void Prime() {
        for(int i = 0; i < 1010; ++i) {
            number[i] = 1;
        }
        for(int i = 2; i < 1010; ++i) {
            if(number[i] == 1) {
                prime[pnum++] = i;
                for(int j = 2*i; j < 1010; j += i) {
                    number[j] = 0;
                }
            }
        }
    }
    
    int minSteps(int n) {
        Prime();
        for(int i = 0; i < pnum; ++i) {
            if(n == prime[i]) {
                return n;
            }
        }
        int ans = 0, i = 0;
        //n的质因子分解
        for(int i = 0; i < pnum; ++i){
            while(n > 0 && n % prime[i] == 0){
                ans += prime[i];
                n /= prime[i];
            }
        }
        
        return ans;
    }
};
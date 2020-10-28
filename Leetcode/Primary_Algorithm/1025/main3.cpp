#include <stdio.h>
#include <iostream>
using namespace std;

/**
@author: ZhengXiaoTao
@description: 3的幂
*/

class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n < 1) return false;
        while(n % 3 == 0) {
            n = n / 3;
        }
        if(n == 1) return true;
        else return false;
    }
};
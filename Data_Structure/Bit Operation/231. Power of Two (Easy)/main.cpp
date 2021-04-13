#include <stdio.h>
#include <iostream>
using namespace std;

/**
@author: ZhengXiaoTao
@description: 
*/


class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 && (n & (n - 1)) == 0; // 2 的幂次方的必要条件
    }
};

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n == 0) return false;
        while(n % 2 == 0) {
            n >>= 1;
        }
        if(n == 1) return true;
        else return false;
    }
};
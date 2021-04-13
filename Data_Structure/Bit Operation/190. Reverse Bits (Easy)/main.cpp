#include <stdio.h>
#include <iostream>
using namespace std;

/**
@author: ZhengXiaoTao
@description: 
*/

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int ret = 0;
        int i = 32;
        while(i--) {
            ret <<= 1;
            ret |= (n & 1); // (n & 1)
            n >>= 1;
        }
        return ret;
    }
};
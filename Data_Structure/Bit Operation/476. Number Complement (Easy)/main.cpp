#include <stdio.h>
#include <iostream>
using namespace std;

/**
@author: ZhengXiaoTao
@description: 
求一个数num的掩码可用这个方法
    int mask = num;
    mask |= mask >> 1;
    mask |= mask >> 2;
    mask |= mask >> 4;
    mask |= mask >> 8;
    mask |= mask >> 16;
*/

class Solution {
public:
    //本题关键就是找对应位相等的掩码111...
    int findComplement(int num) {
        int temp = num, mask = 0;
        while(temp > 0) {
            temp >>= 1;
            mask = (mask << 1) + 1;
        }
        return num ^ mask;
    }
};
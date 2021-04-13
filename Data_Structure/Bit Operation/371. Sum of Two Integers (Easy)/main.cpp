#include <stdio.h>
#include <iostream>
using namespace std;

/**
@author: ZhengXiaoTao
@description: 
*/


class Solution {
public:
    int getSum(int a, int b) {
        // a ^ b是没有进位的和
        // (a & b) << 1 是a和b做运算的进位
        return b = 0 ? a : getSum((a ^ b), (a & b) << 1);
    }
};
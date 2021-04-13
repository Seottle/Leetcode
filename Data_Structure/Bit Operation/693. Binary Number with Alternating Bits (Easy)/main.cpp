#include <stdio.h>
#include <iostream>
using namespace std;

/**
@author: ZhengXiaoTao
@description: 
*/

class Solution {
public:
    bool hasAlternatingBits(int n) {
        long long a = (n ^ (n >> 1)); // 当出现相邻01的情况时，会发现，当其右移1位的结果相互异或，得到的总是全1
        return (a & (a + 1)) == 0;
        // 不能直接说判断  a+1 == 0 ！妈的又不是二进制相加！ 你要用a&(a+1)才能体现出二进制相加
    }
};
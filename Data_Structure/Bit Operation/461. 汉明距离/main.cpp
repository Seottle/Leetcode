#include <stdio.h>
#include <iostream>
using namespace std;

/**
@author: ZhengXiaoTao
@description: 
*/


class Solution {
public:
    int hammingDistance(int x, int y) {
        // >> 右移 箭头指向哪边就是往哪边移动
        int z = x ^ y;
        int cnt = 0;
        while(z != 0) {
            //利用 x & 0s = 0 和 x & 1s = x 的特点，可以实现掩码操作。
            //一个数 num 与 mask：00111100 进行位与操作，只保留 num 中与 mask 的 1 部分相对应的位。
            if((z & 1) == 1) cnt++; // 相当于和0001做与运算，有1就加
            z = z >> 1;
        }
        return cnt;
    }
};
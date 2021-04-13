#include <stdio.h>
#include <iostream>
using namespace std;

/**
@author: ZhengXiaoTao
@description: 
*/


class Solution {
public:
    int missingNumber(vector<int>& nums) {
        //一个数进行两次完全相同的异或运算会得到原来的数
        //未缺失的数在[0..n] 和数组中各出现一次，因此异或后得到 0。
        //缺失的数只出现一次，故会得到他本身
        int c = nums.size();
        for(int i = 0; i < nums.size(); ++i) {
            c ^= i ^ nums[i];
        }
        return c;
    };
};
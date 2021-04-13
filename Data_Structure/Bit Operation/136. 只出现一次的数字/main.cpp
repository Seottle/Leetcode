#include <stdio.h>
#include <iostream>
using namespace std;

/**
@author: ZhengXiaoTao
@description: 
*/


class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // 利用 x ^ 1s = ~x 的特点，可以将一个数的位级表示翻转； x ^ 0 = x
        // 利用 x ^ x = 0 的特点，可以将三个数中重复的两个数去除，只留下另一个数。1^1^2 = 2
        int c = 0;
        for(int i = 0; i < nums.size(); ++i) {
            c = c ^ nums[i];
        }
        return c;
    }
};
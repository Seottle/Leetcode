#include <stdio.h>
#include <iostream>
using namespace std;

/**
@author: ZhengXiaoTao
@description: 2020.11.6 最大子序列和
*/


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max = INT_MIN, temp = 0;
        int len = nums.size();
        for(int i = 0; i < len; ++i) {
            temp += nums[i];
            if(temp > max) {
                max = temp;
            }
            if(temp < 0) {
                temp = 0;
            }
        }
        return max;
    }
};
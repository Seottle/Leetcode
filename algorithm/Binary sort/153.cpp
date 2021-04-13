#include <stdio.h>
#include <iostream>
using namespace std;

/**
@author: ZhengXiaoTao
@description: 2020.11.8 寻找旋转排序数组中的最小值
*/


class Solution {
public:
    int findMin(vector<int>& nums) {
        int len = nums.size();
        int i = 0, j = len - 1;
        while(nums[i] > nums[j]) {
            i++;
        }
        return nums[i];
        
    }
};
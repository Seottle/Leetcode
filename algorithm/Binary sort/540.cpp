#include <stdio.h>
#include <iostream>
using namespace std;

/**
@author: ZhengXiaoTao
@description: 2020.11.8有序数组中的单一元素
*/


class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int len = nums.size();
        if(len <= 1) return nums[0];
        int i = 0;
        while(nums[i + 1] == nums[i]) {
            i = i + 2;
        }
        return nums[i];    
    }
};
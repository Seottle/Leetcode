#include <stdio.h>
#include <iostream>
using namespace std;

/**
@author: ZhengXiaoTao
@description: 
*/


class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> ans(2, 0);
        int diff = 0;
        for(int i = 0; i < nums.size(); ++i) {
            diff = diff ^ nums[i];
        }
        diff &= -diff; //得到diff最右侧不为0的位
        for(int i = 0; i < nums.size(); ++i) {
            if((diff & nums[i]) == 0) ans[0] ^= nums[i];
            else ans[1] ^= nums[i];
        }
        return ans;
    }
};
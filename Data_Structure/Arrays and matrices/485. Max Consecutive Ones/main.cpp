#include <stdio.h>
#include <iostream>
using namespace std;

/**
@author: ZhengXiaoTao
@description: 
*/


class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cnt = 0;
        int ret = 0;
        for(int i = 0; i < nums.size(); ++i) {
            if(nums[i] == 1) {
                cnt++;
            }
            else {
                ret = max(ret, cnt);
                cnt = 0;
            }
        }
        ret = max(ret, cnt);
        return ret;
    }
};
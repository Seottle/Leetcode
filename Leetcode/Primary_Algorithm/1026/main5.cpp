#include <stdio.h>
#include <iostream>
using namespace std;

/**
@author: ZhengXiaoTao
@description: 缺失的数字
*/


class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int hash[n + 10];
        memset(hash, 0, sizeof(hash));
        for(int i = 0; i < n; ++i) {
            hash[nums[i]]++;
        }
        int i;
        for(i = 0; i < n + 10; ++i) {
            if(hash[i] == 0) break;
        }
        return i;
    }
};
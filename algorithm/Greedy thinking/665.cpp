#include <stdio.h>
#include <iostream>
using namespace std;

/**
@author: ZhengXiaoTao
@description: 2020.11.5 非递减数列
解题思路： 从拐点开始研究，当出现非递增情况时，说明此时的i是拐点，就要讨论此时i的情况
i 从1开始，因为拐点的变化取决于其前面点的情况，如果nums[i] >= nums[i - 1] 就正确
假如一开始就出现nums[i] < nums[i - 1] ，那直接把nums[i - 1] 变成nums[i] 递增序列，越小越好，
当i > 1时，就要看此时i 的值与 i - 2的值的比较了，如果i 比 i - 2 大，最好的办法就是把i变大，也即nums[i] = nums[i - 1] (nums[i - 1] 肯定大于 nums[i - 2])
否则把nums[i - 1] 变小， 也即 nums[i - 1] = nums[i]   (nums[i - 1] 肯定大于 nums[i - 2])
*/

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int cnt = 0;
        int len = nums.size();
        for(int i = 1; i < len; ++i) {
            if(nums[i - 1] <= nums[i]) continue;
            cnt++;
            if(i - 2 >= 0 && nums[i] < nums[i - 2]) nums[i] = nums[i - 1];
            else nums[i - 1] = nums[i];
            if(cnt > 1) return false;
        } 
        return true;
    }
};
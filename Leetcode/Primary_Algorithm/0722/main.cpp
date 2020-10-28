#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

/**
@author: ZhengXiaoTao
@description: 
给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。
输入: [2,2,1]
输出: 1

输入: [4,1,2,1,2]
输出: 4
*/
int singleNumber(int *nums, int numsSize) {
        sort(nums, nums + numsSize);
        int i;
        for(i = 0; i < numsSize - 1; ++i) {
            if(nums[i] != nums[i + 1]) {
            	break;
            }
            i++;
        }
        return nums[i];
    }

int main() {
    int nums[3] = {2, 2, 1};
    int ans = singleNumber(nums, 3);
    
    cout << ans << endl;
    return 0;
}
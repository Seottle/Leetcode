#include <stdio.h>
#include <iostream>
using namespace std;

/**
@author: ZhengXiaoTao
@description: 两数之和 II - 输入有序数组
经典双指针求在已排序的数组中求两个值等于一个值，这个思路应该要有，一头一尾的准则。和如果大了尾--，小了头++

*/


class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans;
        int i = 0, j = numbers.size() - 1;
        while(i < j) {
            if(numbers[i] + numbers[j] > target) {
                j--;
            }
            else if(numbers[i] + numbers[j] < target) {
                i++;
            }
            else{
                ans.push_back(i);
                ans.push_back(j);
            }
        }      
        return ans;
    }
};

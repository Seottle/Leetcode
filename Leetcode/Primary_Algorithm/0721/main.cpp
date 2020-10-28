#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

/**
@author: ZhengXiaoTao
@description: 给定一个整数数组，判断是否存在重复元素。

如果任意一值在数组中出现至少两次，函数返回 true 。如果数组中每个元素都不相同，则返回 false 。
*/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set <int> Myset(nums.begin(), nums.end());
        if(Myset.size() != nums.size()) return true;
        else return false;
    }
};
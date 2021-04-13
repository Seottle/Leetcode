#include <stdio.h>
#include <iostream>
using namespace std;

/**
@author: ZhengXiaoTao
@description: 
*/

//利用优先队列与生俱来的排序特性
class Solution {
public:
    void sortColors(vector<int>& nums) {
        priority_queue<int> Q;
        for(int i : nums) {
            Q.push(i);
        }
        int len = nums.size() - 1;
        while(!Q.empty()) {
            nums[len--] = Q.top();
            Q.pop();
        }
    }
};
//双指针：p0记录0，p2记录2
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int p0 = 0, p2 = nums.size() - 1;
        for(int i = 0; i < nums.size(); ++i) {
            while(i <= p2 && nums[i] == 2) {
                swap(nums[i], nums[p2]);
                p2--;
            }
            if(nums[i] == 0) {
                swap(nums[i], nums[p0]);
                p0++;
            }
        }
    }
};
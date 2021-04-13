#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

/**
@author: ZhengXiaoTao
@description: 2020/10/30 数组中的第K个最大元素
*/

/*
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int len = nums.size();
        return nums[len - k];
    }
};
*/
void swap(int i, int j) {
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
}

int Partition(int left, int right) {
   int mid = left + (right - left) / 2;
   swap(left, mid); 
   while (left < right)
   {
       while(left < right && nums[left] <= nums[right]) --right;
       swap(left, right);
       while (left < right && nums[left] <= nums[right]) ++left;
       swap(left, right);
   }
   return left;
}

int Quicksort(int left, int right, int  k) {
    int position = Partition(left, right);
    if(position == k - 1) {
        return position;
    }
    else if(position < k - 1) {
        Partition(position + 1, right, k);
    }
    else Partition(left, position - 1, k);
}
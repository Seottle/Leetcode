#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

/**
@author: ZhengXiaoTao
@description: 合并两个数组 双指针从后往前
题目已知的是两个升序数组，且元素个数m和n都已知，并且nums1的长度是m+n，所以我们可以用双指针从后往前的办法
以nums2的n个元素插入nums1用完为结束条件，m，n分别指向元数个数的末尾，len指向nums1数组的末尾
///先while！！把nums1大于nums2的放到最后///当nums1[m] > nums2[n] 时，说明nums1的最大数大于nums2的最大数，故将nums1[m] 和 nums1[len] 交换，然后m--,len--
当nums1[m] < nums2[n] 时，说明nums1的最大数小于nums2的最大数，故将nums2[n] 插入nums1[len] （相当于交换，因为nums1后面都为0）, n--,len--
*/


class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int len = nums1.size() - 1;
        m--;
        n--;
        while(n >= 0) {

            while(m >= 0 && nums1[m] > nums2[n]) {
                swap(nums1[m--], nums1[len--]);
            }
            
            swap(nums1[len--], nums2[n--]);
            
        }
    }
};
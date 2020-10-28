#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

/**
@author: ZhengXiaoTao
@description: 将有序数组转换为二叉搜索树
*/


class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int len = nums.size();
        return Binaryarray(nums, 0, len - 1);
    }
    TreeNode* Binaryarray(vector<int>& nums, int left, int right) {
        if(left > right) return NULL;
        int mid = (left + right) / 2; //防止溢出
        TreeNode* ans = new TreeNode(nums[mid]);
        ans -> left = Binaryarray(nums, left, mid - 1);
        ans -> right = Binaryarray(nums, mid + 1, right);
        return ans;
    }
};

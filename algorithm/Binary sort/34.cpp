#include <stdio.h>
#include <iostream>
using namespace std;

/**
@author: ZhengXiaoTao
@description: 2020.11.9

vector初始化!  vector<int> ans(2, -1); // 2个-1
               vector<int> ans = {-1, -1};
*/

class Solution {
public:
    int Findhigherboud(vector<int>&nums, int target){
        int left = 0, right = nums.size() - 1; //假设存在，则target值一定在数组的范围内
                                            //故left和right的范围是0-nums.size()-1
        int res = -1;
        while(left <= right) { //left <= right  答案在循环里，适用于找边界问题
                int mid = left + (right - left) / 2;
                if(nums[mid] == target) {
                    //找左边界，如果遇到相等不要结束，继续往右边找
                    res = mid;
                    left = mid + 1;
                }
                else if(nums[mid] > target) {
                    right = mid - 1;
                }
                else left = mid + 1;
            }
        return res;
        }
    int Findlowerboud(vector<int>&nums, int target){
        int left = 0, right = nums.size() - 1; //假设存在，则target值一定在数组的范围内
                                            //故left和right的范围是0-nums.size()-1
        int res = -1;
        while(left <= right) { //left <= right  答案在循环里，适用于找边界问题
            int mid = left + (right - left) / 2;
            if(nums[mid] == target) {
                //找右边界，如果遇到相等不要结束，继续往左边找
                res = mid;
                right = mid - 1;
            }
            else if(nums[mid] > target) {
                right = mid - 1;
            }
            else left = mid + 1;
        }
        return res;
    }
    vector<int> searchRange(vector<int>& nums, int target){
        vector<int> ans = {-1, -1};
        if(nums.empty()) return ans;
        //找左边界
        int left = Findlowerboud(nums, target);
        if(left == -1) return ans;
        ans[0] = left;
        //找右边界
        int right = Findhigherboud(nums, target);
        ans[1] = right;
        return ans;
    }
};
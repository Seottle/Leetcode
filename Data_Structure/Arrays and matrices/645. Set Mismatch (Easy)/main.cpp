class Solution {
public: 
    void swap(vector<int>& nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }   
    vector<int> findErrorNums(vector<int>& nums) {
        //先把不在对应位置的元素交换
        for(int i = 0; i < nums.size(); ++i) {
            while(nums[i] != i + 1 && nums[i] != nums[nums[i] - 1]) {
                swap(nums, i, nums[i] - 1);
            }
        }
        for(int i = 0; i < nums.size(); ++i) {
            if(nums[i] != i + 1) {
                return {nums[i], i + 1};
            }
        }
        return {};
    }   
};      

class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        cnt = 0
        length = len(nums)
        for i in range(length) :
            if nums[i] != 0:
                nums[cnt] = nums[i]
                cnt += 1
        while length - cnt > 0:
            nums[cnt] = 0
            cnt += 1
        return nums
        
            

class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        before = len(nums)
        s = set(nums)
        after = len(s)
        if before != after: 
            return True
        else: 
            return False
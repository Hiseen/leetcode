class Solution:
     def twoSum(self, nums, target):
         """
         :type nums: List[int]
         :type target: int
         :rtype: List[int]
         """
         for i in range(len(nums)):
             e=target-nums[i]
             if e in nums[i+1:]:
                 return [i,i+1+nums[i+1:].index(e)]
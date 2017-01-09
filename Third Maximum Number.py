class Solution(object):
     def thirdMax(self, nums):
         """
         :type nums: List[int]
         :rtype: int
         """
         t=set(nums)
         if len(t)<3:
             return max(t)
         else:
             return sorted(t)[-3]
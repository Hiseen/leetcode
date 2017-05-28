class Solution:
     def findUnsortedSubarray(self, nums):
         """
         :type nums: List[int]
         :rtype: int
         """
         if len(nums)<2:
             return 0
         nums2=sorted(nums)
         s=0
         e=len(nums)-1
         while s<e:
             if nums2[s]==nums[s] and nums2[e]==nums[e]:
                 s+=1
                 e-=1
             elif nums2[s]==nums[s]:
                 s+=1
             elif nums2[e]==nums[e]:
                 e-=1
             else:
                 return 1+e-s
         return 0
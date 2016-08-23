class Solution(object):
     def containsNearbyDuplicate(self, nums, k):
         """
         :type nums: List[int]
         :type k: int
         :rtype: bool
         """
         d={}
         for i,j in enumerate(nums):
             if j in d:
                 if abs(d[j]-i)<=k:
                     return True
                 else:
                     d[j]=i
             else:
                 d[j]=i
         return False
         
class Solution:
     def findLHS(self, nums):
         """
         :type nums: List[int]
         :rtype: int
         """
         d={}
         for i in nums:
             if i in d:
                 d[i]+=1
             else:
                 d[i]=1
         res=0
         for i in d:
             if i+1 in d:
                 res=max(res,d[i]+d[i+1])
         return res
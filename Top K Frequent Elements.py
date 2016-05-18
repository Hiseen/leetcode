class Solution(object):
     def topKFrequent(self, nums, k):
         """
         :type nums: List[int]
         :type k: int
         :rtype: List[int]
         """
         temp={}
         for i in nums:
             if i not in temp:
                 temp[i]=1
             else:
                 temp[i]+=1
         return sorted(temp,key=lambda x:temp[x],reverse=True)[:k]
         
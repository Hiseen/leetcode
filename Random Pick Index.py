from collections import defaultdict
 class Solution(object):
     def __init__(self, nums):
         """
         :type nums: List[int]
         :type numsSize: int
         """
         self.nums=nums
 
     def pick(self, target):
         """
         :type target: int
         :rtype: int
         """
         res=[]
         for i in range(len(self.nums)):
             if self.nums[i]==target:
                 res.append(i)
         return random.choice(res)
 
 
 # Your Solution object will be instantiated and called as such:
 # obj = Solution(nums)
 # param_1 = obj.pick(target)
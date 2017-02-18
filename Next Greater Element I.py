class Solution(object):
     def nextGreaterElement(self, findNums, nums):
         """
         :type findNums: List[int]
         :type nums: List[int]
         :rtype: List[int]
         """
         result=[]
         for i in findNums:
             flag=0
             for j in nums:
                 if i==j:
                     flag=1
                 elif flag and i<j:
                     result.append(j)
                     flag=2
                     break
             if flag!=2:
                 result.append(-1)
         return result
             
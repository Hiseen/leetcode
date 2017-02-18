class Solution(object):
     def findRelativeRanks(self, nums):
         """
         :type nums: List[int]
         :rtype: List[str]
         """
         d={i:j for i,j in enumerate(nums)}
         count=1
         for i in sorted(d,key=lambda x:d[x],reverse=True):
             if count==1:
                 nums[i]="Gold Medal"
             elif count==2:
                 nums[i]="Silver Medal"
             elif count==3:
                 nums[i]="Bronze Medal"
             else:
                 nums[i]=str(count)
             count+=1
         return nums
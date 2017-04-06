# Definition for an interval.
 # class Interval(object):
 #     def __init__(self, s=0, e=0):
 #         self.start = s
 #         self.end = e
 class Solution(object):
     def findRightInterval(self, intervals):
         """
         :type intervals: List[Interval]
         :rtype: List[int]
         """
         def binary_search(l,target):
             hi=len(l)
             lo=0
             while hi>lo:
                 mid=lo+(hi-lo)/2
                 if l[mid]>target:
                     hi=mid
                 elif l[mid]<target:
                     lo=mid+1
                 else:
                     return target
             return l[lo]
         res=[]
         m=max(i.start for i in intervals)
         d={j.start:i for i,j in enumerate(intervals)}
         l=sorted(i.start for i in intervals)
         for i in intervals:
             if i.end>m:
                 res.append(-1)
             else:
                 res.append(d[binary_search(l,i.end)])
         return res
         
class Solution(object):
     def findMinArrowShots(self, points):
         """
         :type points: List[List[int]]
         :rtype: int
         """
         points=sorted(points,key=lambda x:(x[1],x[0]))
         arrow=-2147483649
         res=0
         for i in points:
             if i[0]>arrow:
                 arrow=i[1]
                 res+=1
         return res
                 
             
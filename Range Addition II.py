class Solution:     def maxCount(self, m, n, ops):         """         :type m: int         :type n: int         :type ops: List[List[int]]         :rtype: int         """         m1=m         m2=n         for i in ops:             if i[0]<m1:                 m1=i[0]             if i[1]<m2:                 m2=i[1]         return m1*m2
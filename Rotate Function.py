class Solution(object):
     def maxRotateFunction(self, A):
         """
         :type A: List[int]
         :rtype: int
         """
         s=sum(A);
         f=0
         for i,j in enumerate(A):
             f+=i*j
         m=f
         l=len(A)
         A=A[1:]
         while len(A):
             f-=l*A[-1]
             f+=s
             if f>m:
                 m=f
             A=A[:-1]
         return m
             
class Solution(object):
     def countArrangement(self, N):
         """
         :type N: int
         :rtype: int
         """
         def recur(N,l):
             if N<=0:return 1
             res=0
             for i in range(N):
                 if l[i]%N==0 or N%l[i]==0:
                     l[i],l[N-1]=l[N-1],l[i]
                     res+=recur(N-1,l)
                     l[i],l[N-1]=l[N-1],l[i]
             return res
         
         return recur(N,range(1,N+1))
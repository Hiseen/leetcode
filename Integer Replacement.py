class Solution(object):
     
     def reduce(self,l,n,times):
         if n==1:
             l.append(times)
         elif n%2==0:
             self.reduce(l,n/2,times+1)
         else:
             self.reduce(l,n-1,times+1)
             self.reduce(l,n+1,times+1)
    
     def integerReplacement(self, n):
         """
         :type n: int
         :rtype: int
         """
         l=[]
         self.reduce(l,n,0)
         return min(l)
class Solution(object):
     def longestPalindrome(self, s):
         """
         :type s: str
         :rtype: int
         """
         from collections import defaultdict
         d=defaultdict(int)
         for i in s:
             d[i]+=1
         res=0
         plusone=False
         if len(d)==1:
             return d[s[0]]
         for i in d:
             if d[i]%2==0:
                 res+=d[i]
             else:
                 res+=d[i]-1
                 plusone=True
         return res+1 if plusone else res
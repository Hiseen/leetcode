class Solution(object):
     def longestPalindrome(self, s):
         """
         :type s: str
         :rtype: str
         """
         if s==s[::-1]:
             return s
         else:
             l=len(s)
             for i in range(l-2,0,-1):
                 for j in range(l-i):
                     ok=True
                     for k in range(0,i//2+1):
                         if s[j+k]!=s[j+i-k]:
                             ok=False
                             break
                     if ok:
                         return s[j:j+i+1]
         return s[0]
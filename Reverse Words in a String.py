class Solution(object):
     def reverseWords(self, s):
         """
         :type s: str
         :rtype: str
         """
         res=""
         for i in s.split()[::-1]:
             res+=i+' '
         return res[:-1]
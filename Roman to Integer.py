class Solution(object):
     def romanToInt(self, s):
         """
         :type s: str
         :rtype: int
         """
         res=0
         m={'I':1,'V':5,'X':10,'L':50,'C':100,'D':500,'M':1000}
         size=len(s)
         index=0
         while index<size:
             l=m[s[index]]
             r=m[s[index+1]] if index+1<size else 0
             if l<r:
                 res+=r-l
                 index+=2
             else:
                 res+=l
                 index+=1
         return res
                 
                 
         
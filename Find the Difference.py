class Solution(object):
     def findTheDifference(self, s, t):
         """
         :type s: str
         :type t: str
         :rtype: str
         """
         h1={}
         h2={}
         for i in s:
             if not i in h1:
                 h1[i]=1
             else:
                 h1[i]+=1
         for i in t:
             if not i in h2:
                 h2[i]=1
             else:
                 h2[i]+=1
         for i in h1:
             if h1[i]==h2[i]:
                 del h2[i]
             else:
                 return i
                 
         for i in h2:
             return i
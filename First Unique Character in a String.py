class Solution(object):
     def firstUniqChar(self, s):
         """
         :type s: str
         :rtype: int
         """
         d={}
         maxindex=len(s)+1
         if maxindex==1:
             return -1
         for index,i in enumerate(s):
             if i in d:
                 d[i]=maxindex
             else:
                 d[i]=index
         result=sorted(d,key=lambda x:d[x])[0]
         return d[result] if d[result]!=maxindex else -1
         
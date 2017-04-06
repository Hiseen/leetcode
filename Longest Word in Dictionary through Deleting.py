class Solution(object):
     def findLongestWord(self, s, d):
         """
         :type s: str
         :type d: List[str]
         :rtype: str
         """
         def contains(l,s):
             if len(l)<len(s):return False
             if len(l)==len(s) and l!=s:return False
             if l==s:return True
             index=0
             for i in s:
                 if l.find(i,index)!=-1:
                     index=l.find(i,index)+1
                 else:
                     return False
             return True
         d=sorted(d,key=lambda x:(-len(x),x))
         for i in d:
             if contains(s,i):
                 return i
         return ""
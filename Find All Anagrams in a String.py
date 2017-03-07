class Solution(object):
     def findAnagrams(self, s, p):
         """
         :type s: str
         :type p: str
         :rtype: List[int]
         """
         from collections import defaultdict
         lenp=len(p)
         lens=len(s)
         temp=defaultdict(int)
         temp2=defaultdict(int)
         for i in s[:lenp]:
             temp[i]+=1
         for i in p:
             temp2[i]+=1
         res=[]
         for i in range(lens-lenp+1):
             if temp2==temp:
                 res.append(i)
             if temp[s[i]]==1:
                 del temp[s[i]]
             else:
                 temp[s[i]]-=1
             if lenp==lens:
                 break
             temp[s[lenp]]+=1
             lenp+=1
         return res
class Solution(object):
     def longestSubstring(self, s, k):
         """
         :type s: str
         :type k: int
         :rtype: int
         """
         sl=[s]
         s1=set(s)
         ns1=set()
         for i in s1:
             if s.count(i)<k:
                 sl=sum((j.split(i) for j in sl),[])
             else:
                 ns1.add(i)
         res=[]
         for i in sl:
             flag=0
             for j in ns1:
                 temp=i.count(j)
                 if temp!=0 and temp<k:
                     flag+=temp
             if flag!=len(i):
                 res.append(len(i)-flag)
         max=0
         for i in res:
             if i>max:
                 max=i
         return max
                 
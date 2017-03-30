class Solution(object):
     def findMaxForm(self, strs, m, n):
         """
         :type strs: List[str]
         :type m: int
         :type n: int
         :rtype: int
         """
         s={(0,m,n)}
         res=0
         last=len(strs)
         for i in strs:
             num0=i.count('0')
             num1=len(i)-num0
             temp=set()
             for j in s:
                 if j[0]+last>res and j[1]>=num0 and j[2]>=num1:
                     if j[0]+1>res:res=j[0]+1
                     temp.add((j[0]+1,j[1]-num0,j[2]-num1))
             last-=1
             s|=temp
         return res
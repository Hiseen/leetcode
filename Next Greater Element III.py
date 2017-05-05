class Solution(object):
     def nextGreaterElement(self, n):
         """
         :type n: int
         :rtype: int
         """
         n=str(n)
         rec=-1
         for i in range(len(n)-1):
             if n[i]<n[i+1]:
                 rec=i
         if rec==-1:
             return -1
         else:
             res=n[:rec]+n[rec+1]+n[rec]+n[rec+2:]
             res=int(res)
             l=[i for i in n[rec+1:]]
             res2=min(i for i in l if i>n[rec])
             l.remove(res2)
             l.append(n[rec])
             res2=int(n[:rec]+res2+''.join(sorted(l)))
             res=min(res,res2)
             if res<=2147483647:
                 return res
             else:
                 return -1
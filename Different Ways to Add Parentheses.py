import re
 class Solution(object):
     def diffWaysToCompute(self, input):
         """
         :type input: str
         :rtype: List[int]
         """
         d={'+':operator.add,'-':operator.sub,'*':operator.mul}
         t=re.split("(\d+)",input)[1:-1]
         t=[t[i] if i%2 else int(t[i]) for i in range(len(t))]
         def helper(l):
             if len(l)==1:return l
             return [d[l[i+1]](j,k) for i in range(0,len(l)-2,2) for j in helper(l[:i+1]) for k in helper(l[i+2:])]
         return helper(t)
         
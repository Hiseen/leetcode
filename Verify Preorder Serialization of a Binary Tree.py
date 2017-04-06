class Solution(object):
     def isValidSerialization(self, preorder):
         """
         :type preorder: str
         :rtype: bool
         """
         preorder=preorder.split(',')
         l=len(preorder)
         if l%2==0:
             return False
         else:
             c1=0
             c2=0
             for i in preorder:
                 if c1-c2==1:
                     return False
                 if i=='#':
                     c1+=1
                 else:
                     c2+=1
             return c1-c2==1
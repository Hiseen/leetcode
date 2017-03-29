from collections import defaultdict
 number_map=(('zero',0),('wto',2),('ufor',4),('xsi',6),('geiht',8),('htree',3),('five',5),('vseen',7),('inne',9),('one',1))
 indexs='0123456789'
 m2=[0 for i in range(10)]
 class Solution(object):
     def originalDigits(self, s):
         """
         :type s: str
         :rtype: str
         """
         m=defaultdict(int)
         for i in s:
             m[i]+=1
         for i in number_map:
             a=m[i[0][0]]
             m2[i[1]]=a
             if a!=0:
                 for j in i[0]:
                     m[j]-=a
         return ''.join(m2[i]*j for i,j in enumerate(indexs))
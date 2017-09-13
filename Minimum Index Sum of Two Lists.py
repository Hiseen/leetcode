class Solution:
     def findRestaurant(self, list1, list2):
         """
         :type list1: List[str]
         :type list2: List[str]
         :rtype: List[str]
         """
         res=[]
         m=2147483647
         for index1,i in enumerate(list1):
             for index2,j in enumerate(list2):
                 if i==j:
                     if index1+index2<m:
                         m=index1+index2
                         res=[i]
                     elif index1+index2==m:
                         res.append(i)
         return res
                         
                     
                     
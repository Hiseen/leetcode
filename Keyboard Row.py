class Solution(object):
     def findWords(self, words):
         """
         :type words: List[str]
         :rtype: List[str]
         """
         l2="qwertyuiop"
         l3="asdfghjkl"
         l4="zxcvbnm"
         result=[]
         for i in words:
             temp=i.lower()
             if all(j in l2 for j in temp) or all(j in l3 for j in temp) or all(j in l4 for j in temp):
                 result.append(i)
         return result
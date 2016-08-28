class Solution(object):
     def longestCommonPrefix(self, strs):
         """
         :type strs: List[str]
         :rtype: str
         """
         if len(strs)==0:
             return ""
         result=len(strs[0]);
         data=strs[0]
         for i in strs[1:]:
             if len(i)<result:
                 result=len(i)
             for j in range(result):
                 if data[j]!=i[j]:
                     result=j
                     break
         return data[:result]
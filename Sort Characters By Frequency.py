class Solution(object):
     def frequencySort(self, s):
         """
         :type s: str
         :rtype: str
         """
         result={}
         for i in s:
             if not i in result:
                 result[i]=1
             else:
                 result[i]+=1
         temp=sorted(result,key=lambda x:(result[x],x),reverse=True)
         return "".join(i*result[i] for i in temp)
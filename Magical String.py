class Solution(object):
     def magicalString(self, n):
         """
         :type n: int
         :rtype: int
         """
         if n==0:return 0
         if n<=2:return 1
     	now=2
     	result="122"
     	while now<n:
     		result+=int(result[now])*("1" if now%2==0 else "2")
     		now+=1
     	result=result[:n]
     	return result.count("1")
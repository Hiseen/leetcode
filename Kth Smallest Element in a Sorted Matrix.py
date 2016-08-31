class Solution(object):
     def kthSmallest(self, matrix, k):
         """
         :type matrix: List[List[int]]
         :type k: int
         :rtype: int
         """
         return sorted(sum(matrix,[]))[k-1];
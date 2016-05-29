class Solution(object):
     def intersect(self, nums1, nums2):
         """
         :type nums1: List[int]
         :type nums2: List[int]
         :rtype: List[int]
         """
         m1,m2={},{}
         for i in nums1:
             if i in m1:
                 m1[i]+=1
             else:
                 m1[i]=1
         for i in nums2:
             if i in m2:
                 m2[i]+=1
             else:
                 m2[i]=1
         return sum(([i for k in range(min(m2[i],m1[i]))] for i in m2 if i in m1),[])
         
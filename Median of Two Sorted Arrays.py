class Solution(object): 
    def findMedianSortedArrays(self, nums1, nums2): 
        """ 
        :type nums1: List[int] 
        :type nums2: List[int] 
        :rtype: float 
        """ 
        temp=sorted(nums1+nums2) 
        if len(temp)%2==1: 
            return temp[len(temp)>>1] 
        else: 
            index=len(temp)>>1 
            return (temp[index]+temp[index-1])/2.0
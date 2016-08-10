class Solution {
 public:
     double helper(vector<int>& nums1, vector<int>&nums2, int beg1, int beg2, int size1, int size2, int k, bool flag)
     {
     	if (size1>size2)
     		return helper(nums2, nums1, beg2, beg1, size2, size1, k, flag);
     	if (!size1)
     		return flag ? (nums2[beg2 + k] + nums2[beg2 + k - 1]) / 2.0 : nums2[beg2 + k];
     	if (k == 1)
     	{
     		if (flag)
     		{
     			int min1 = std::min(nums1[beg1], nums2[beg2]);
     			int min2;
     			if (min1 == nums1[beg1])min2 = 1<size1 ? std::min(nums1[beg1 + 1], nums2[beg2]) : nums2[beg2];
     			else min2 = 1<size2 ? std::min(nums1[beg1], nums2[beg2 + 1]) : nums1[beg1];
     			return (min1 + min2) / 2.0;
     		}
     		else
     		{
     			int min1= std::min(nums1[beg1], nums2[beg2]);
     			if (min1 == nums1[beg1])return 1 < size1 ? std::min(nums1[beg1 + 1], nums2[beg2]) : nums2[beg2];
     			else return 1<size2 ? std::min(nums1[beg1], nums2[beg2 + 1]) : nums1[beg1];
 		    }
     	}
     	int d1 = std::min(k / 2, size1);
     	int d2 = k - d1;
     	if (nums1[beg1 + d1 - 1]<nums2[beg2 + d2 - 1])
     		return helper(nums1, nums2, beg1 + d1, beg2, size1 - d1, size2, k - d1, flag);
     	else if (nums1[beg1 + d1 - 1]>nums2[beg2 + d2 - 1])
     		return helper(nums1, nums2, beg1, beg2 + d2, size1, size2 - d2, k - d2, flag);
     	else if (!flag)
     		return std::min(nums1[beg1 + d1],nums2[beg2+d2]);
     	else
     		if (d1 < size1)
     			return (nums1[beg1 + d1 - 1] + std::min(nums1[beg1 + d1], nums2[beg2 + d2])) / 2.0;
     		else
     			return (nums1[beg1 + d1 - 1] + nums2[beg2 + d2]) / 2.0;
     }
 
 double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
 	int size1 = nums1.size(), size2 = nums2.size();
 	if (!size1 && !size2)
 		return 0;
 	if (!size1)
 		return size2 % 2 ? nums2[size2 >> 1] : (nums2[size2 >> 1] + nums2[(size2 >> 1) - 1]) / 2.0;
 	if (!size2)
 		return size1 % 2 ? nums1[size1 >> 1] : (nums1[size1 >> 1] + nums1[(size1 >> 1) - 1]) / 2.0;
 	return helper(nums1, nums2, 0, 0, size1, size2, (size1 + size2) / 2, !(size1 % 2 ^ size2 % 2));
 }
 
 };
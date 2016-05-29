class Solution {
 public:
     vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
         unordered_set<int> set1,set2,resultset;
         int size1=nums1.size(),size2=nums2.size();
         for(int i=0;i<size1;++i)
             set1.insert(nums1[i]);
         for(int i=0;i<size2;++i)
             set2.insert(nums2[i]);
         vector<int> result;
         if(size2>size1)
         {
             for(int i=0;i<size1;++i)
                 if(set2.find(nums1[i])!=set2.end() && resultset.find(nums1[i])==resultset.end())
                 {
                     result.push_back(nums1[i]);
                     resultset.insert(nums1[i]);
                 }
         }
         else
         {
             for(int i=0;i<size2;++i)
                 if(set1.find(nums2[i])!=set1.end() && resultset.find(nums2[i])==resultset.end())
                 {
                     result.push_back(nums2[i]);
                     resultset.insert(nums2[i]);
                 }
         }
         return result;
     }
 };
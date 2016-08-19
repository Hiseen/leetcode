class Solution {
 public:
     void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
         int index=0;
         for(int i=0;i<m;++i)
         {
             if (index == n)break;
             if(nums1[i]>=nums2[index])
             {
                 nums1.insert(nums1.begin()+i,nums2[index]);
                 index++;
                 m++;
             }
         }
     	nums1.erase(nums1.begin()+m,nums1.end());
         while(index<n)
             nums1.push_back(nums2[index++]);
     }
 };
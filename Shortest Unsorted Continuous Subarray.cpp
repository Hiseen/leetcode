class Solution {
 public:
     int findUnsortedSubarray(vector<int>& nums) {
         if(nums.size()<2)return 0;
         int l=-1,r=-1;
         vector<int> c(nums);
         sort(nums.begin(),nums.end());
         for(int i=0;i<nums.size();++i)
         {
             if(c[i]!=nums[i])
             {
                 l=i;
                 break;
             }
         }
         for(int i=nums.size()-1;i>=0;--i)
         {
             if(c[i]!=nums[i])
             {
                 r=i;
                 break;
             }
         }
         if(r==-1)return 0;
         return r-l+1;
         
     }
 };
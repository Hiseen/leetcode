class Solution {
 public:
     bool increasingTriplet(vector<int>& nums) {
         int m1=INT_MAX,m2=INT_MAX;
         int size=nums.size();
         for(int i=0;i<size;++i)
         {
             if(nums[i]<=m1)
                 m1=nums[i];
             else if(nums[i]<=m2)
                 m2=nums[i];
             else
                 return true;
         }
         return false;
     }
 };
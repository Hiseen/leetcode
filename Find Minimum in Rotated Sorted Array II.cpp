class Solution {
 public:
     int findMin(vector<int>& nums) {
         int min=INT_MAX;
         int last=nums[0];
         if(nums.size()==1)return last;
         for(auto i:nums)
         {
             if(i<last)return i;
         }
         return last;
     }
 };
class Solution {
 public:
     int searchInsert(vector<int>& nums, int target) {
         if(nums.size()==0 || target<nums[0])return 0;
         int size=nums.size();
         for(int i=0;i<size;++i)
         {
             if(nums[i]>=target)
                 return i;
         }
         return size;
     }
 };
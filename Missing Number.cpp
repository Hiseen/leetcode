class Solution {
 public:
     int missingNumber(vector<int>& nums) {
         int size=nums.size();
         int result=0;
         for(int i=1;i<=size;++i)
         {
             result^=i;
             result^=nums[i-1];
         }
         return result;
     }
 };
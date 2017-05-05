class Solution {
 public:
     vector<int> searchRange(vector<int>& nums, int target) {
         vector<int> res;
         auto l=lower_bound(nums.begin(),nums.end(),target);
         auto r=upper_bound(nums.begin(),nums.end(),target);
         if(l==nums.end())
             return {-1,-1};
         else
         {
             if(r==nums.begin() && nums[0]!=target)
                 return {-1,-1};
             else if(*l!=target)
                 return {-1,-1};
             return {l-nums.begin(),r-nums.begin()-1};
         }
     }
 };
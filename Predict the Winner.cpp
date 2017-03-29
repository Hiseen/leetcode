
 class Solution {
 public:
 
     int helper(const vector<int>& nums,int lo,int hi)
     {
         return lo==hi?nums[lo]:max(nums[lo]-helper(nums,lo+1,hi),nums[hi]-helper(nums,lo,hi-1));
     }
 
     bool PredictTheWinner(vector<int>& nums) {
        return helper(nums,0,nums.size()-1)>=0;
     }
 };
class Solution {
 public:
     int minMoves(vector<int>& nums) {
         int min=INT_MAX;
         int res=0;
         for(auto i:nums)
         {
             res+=i;
             if(min>i)min=i;
         }
         return res-min*nums.size();
     }
 };
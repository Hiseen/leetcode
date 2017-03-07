class Solution {
 public:
     vector<int> findDuplicates(vector<int>& nums) {
         sort(nums.begin(),nums.end());
         int size=nums.size();
         vector<int> res;
         for(int i=0;i<size;)
         {
             if(nums[i]==nums[i+1])
             {
                 res.push_back(nums[i]);
                 i+=2;
             }
             else
                 ++i;
         }
         return res;
     }
 };